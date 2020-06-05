%{

#include "includes.hpp"
#define NG(x) (nget(prim_table,x))



#define primchek(f,c,m) {size_t n,t=(size_t)(m);\
	if(t<num_prims && (n=(size_t)(nget(prim_table,t)))){\
				\
				t_add(f,svm_p##c);\
				t_add(f,n);\
			}\
			else{\
				t_add(f,svm_##c);\
				t_add(f,t);\
			}\
}



struct listliststring {
		t_list l;
        t_list ll;
        char* s;
};

struct numandstring {
    unsigned int n;
    char* s;
};

struct justlist {
  t_list jl;
};
%}



%union {
unsigned int uint4;
struct listliststring* lls;
struct numandstring* ns;
struct justlist* jl;
}

%type <jl> endresult literal object_core object_core2 statements statement item items items2 wordlist wl wl_item wl_not_word_at_start
%type <uint4> word word_q symbol wordset wordfrom
%type <lls> keyword2list
%type <ns> keyword keyword2

%left LOW

%token PERIOD ARGHOLDER

%right WORDSET WORDSET_Q WORDFROM WORDFROM_Q WORDSET_K WORDSET_K_Q WORDFROM_K WORDFROM_K_Q

%left COMBIN

%left INITIAL_KEYWORD
%left INITIAL_KEYWORD2
%left INITIAL_SYMBOL
%left INITIAL_WORD

%left KEYWORD
%left KEYWORD2
%left SYMBOL
%left AWORD AWORD_D AWORD_Q AWORD_Q_D KEYWORD_Q SYMBOL_Q LITERAL_FLOAT LITERAL_STRING LITERAL_DEC LITERAL_FLOAT_NEG LITERAL_DEC_NEG LITERAL_BIN LITERAL_HEX

%left LB RB
%left LCB RCB
%left LSB RSB


%%

endresult: object_core2 {
	$$=newnew (justlist);
	$$->jl=newtlist;
	t_addlist($$->jl,$1->jl);
	if($1->jl->taintlist!=0){
		t_addlist($$->jl,$1->jl->taintlist);
		t_add($$->jl,svm_ctos);
	}
	return((int)($$->jl));}//was execute_interp($$);need to return $$ as int
;




object_core: object_core2 {
			$$=newnew (justlist);
			$$->jl=newtlist;
			if($1->jl->taintlist!=0){
				t_add($$->jl,svm_seteval);
				//t_add($$->jl,reinterpret_cast<void*>(&($1->jl->taintlist)));//was & not cast
				$$->jl->additem($1->jl->taintlist);
				//printf("DEBUG %d %d\n",$1->jl->taintlist->numberin,&($1->jl->taintlist));
				//size_t f;
				//iterate($1->jl->taintlist,size_t,f)
				//	printf(":%d:",f);
				//enditerate
				//printf("\n");
				
				if ($1->jl->args!=0){
					$1->jl->taintlist->args=$1->jl->args;//DODGEEE INDEED
				}
            //if($1->taintlist->args!=0)svmprint("YO!");
			}
			t_addlist($$->jl,$1->jl);
			$$->jl->taintlist=0;
			$$->jl->taintflag=0;
			$$->jl->isanobjectcore=1;
         //if($$->args!=0)svmprint("[%d] ",$$);
}
;


object_core2:
	statements items {
		$$=newnew (justlist);
		$$->jl=$1->jl;
		t_addlist($$->jl,$2->jl);
	}
	| statements {
		$$=newnew (justlist);
		$$->jl=$1->jl;
	}
	| items {
		$$=newnew (justlist);
		$$->jl=$1->jl;
	}
;


//SO: 	items is either a list of items complete with ctos tainted OR an empty list with a sublist of taints untainted
//	statement is identical to items
//	statementS is a concat of statements/items- both the main items list and sublists
// therefore object_core is a complete concat too. this is where we will sort it out... (finally!)



statements: statement {
	$$=newnew (justlist);
	$$->jl=$1->jl;
	}
	| statements statement {
		$$=newnew (justlist);
		$$->jl=$1->jl;
		t_addlist($$->jl,$2->jl);
	}
;



statement: items PERIOD {
	$$=newnew (justlist);
	$$->jl=$1->jl;
	}
		   | ARGHOLDER {
			char* temp;
			$$=newnew (justlist);
			$$->jl=newtlist;
			$$->jl->args=newlist;
			makestring_strip_last(temp,yytext);
			add($$->jl->args,lookup(temp)+2);
		
		   }
;

items: items2 {


if($1->jl->taintflag==1){
	$$=newnew (justlist);
	$$->jl=$1->jl;
	t_add($$->jl,svm_ctos);
	if($$->jl->extractos==1 && $$->jl->wordset==0){
            t_add($$->jl,svm_ctos);//if there was an evals in the statement and the statement was assignment- extra clear stack
            //NEW! (unless wordset was the first item, in which case no extractos. this is for x->void. etc.)
			//$$->extractos==0; //might have to unrem this!
	}
}//only double ctos if evals....
else {
			$$=newnew (justlist);
			$$->jl=newtlist;

                        //if($1->taintflag2==1 && $1->wordset==1){svmprint("FSCKYOU");}

                        if(($1->jl->taintflag2==1) && ($1->jl->extractos==1 && $1->jl->wordset==0))
                            {t_add($1->jl,svm_ctos);}//NEW LINE- if evals/nevals in statement and stmt was <- extra clear stack in order
			$$->jl->taintlist=$1->jl;
   //                     if($1->extractos==1)add($$->taintlist,svm_ctos);
}

}
;


items2: item %prec COMBIN {
	$$=newnew (justlist);
	$$->jl=$1->jl;
}
| items2 item %prec COMBIN {
	$$=newnew (justlist);
	$$->jl=$1->jl;
	t_addlist($$->jl,$2->jl);
}
;


keyword2list: keyword2 item %prec KEYWORD2
    {   $$=newnew (listliststring);
        
		//$$->l=newtlist;

		$$->l=$2->jl;
        $$->ll=newtlist;
		t_add($$->ll,($1->n)+1);
        makestring($$->s,$1->s);
        //svmprint("1%s",$$->s);
    }
| keyword2list keyword2 item  %prec KEYWORD2
{   $$=newnew (listliststring);//svmprint("TAIL");
    
	//$$->l=newtlist;
	
	$$->l=$1->l;
	t_addlist($$->l,$3->jl);
    $$->ll=newtlist;
	t_add($$->ll,($2->n)+1);
	t_addlist($$->ll,$1->ll);
    makestring_plus($$->s,$1->s,$2->s);
    //svmprint("2%s",$$->s);
}
;


item:	wordlist {$$->jl=$1->jl;}

| item symbol item %prec SYMBOL {
	$$=newnew (justlist);
	$$->jl=$3->jl;
	t_addlist($$->jl,$1->jl);
	primchek($$->jl,evalx,$2)
	t_add($$->jl,1);
}//t_add($$->jl,svm_evala);t_add($$->jl,$2);}

| keyword item keyword2list %prec INITIAL_KEYWORD2
{
    char* ts;
	$$=newnew (justlist);
    $$->jl=$2->jl;
	t_addlist($$->jl,$3->l);//t_addlist($$,$1);
    //t_add($$,svm_evalxs);
    makestring_plus(ts,$1->s,$3->s);primchek($$->jl,evalxs,lookup(ts)+2)//t_add($$,lookup(ts)+2);
    t_add($$->jl,($3->ll->numberin)+1);
	//t_addlist($$,$3->ll);t_add($$,($1->n)+1); THIS WAS ARG #S IN REVERSE ORDER- NO LONGER USED

}

| keyword item %prec INITIAL_KEYWORD {
		$$=newnew (justlist);
		$$->jl=$2->jl;primchek($$->jl,evalxs,$1->n)
		t_add($$->jl,1);
	}//t_add($$,svm_evalas);t_add($$,$1->n);}

| symbol item %prec INITIAL_SYMBOL {
	$$=newnew (justlist);
	$$->jl=$2->jl;
	primchek($$->jl,evalxs,$1)
	t_add($$->jl,1);
}//t_add($$,svm_evalas);t_add($$,$1);}

| item keyword item keyword2list %prec INITIAL_KEYWORD2 //WAS INITIAL_KEYWORD2- wrong wrong wrong! parse errors!
{   char* ts;
	$$=newnew (justlist);
    $$->jl=$3->jl;
	t_addlist($$->jl,$4->l);
	t_addlist($$->jl,$1->jl);//t_add($$,svm_evalx);
    makestring_plus(ts,$2->s,$4->s);
	primchek($$->jl,evalx,lookup(ts)+2)//t_add($$,lookup(ts)+2);
    t_add($$->jl,($4->ll->numberin)+1);
	//t_addlist($$,$4->ll);t_add($$,($2->n)+1); THIS WAS ARG #S IN REVERSE ORDER- NO LONGER USED
    // svmprint("3%s",ts);
}

| item keyword item %prec KEYWORD {
	$$=newnew (justlist);
	$$->jl=$3->jl;
	t_addlist($$->jl,$1->jl);
	primchek($$->jl,evalx,$2->n)
	t_add($$->jl,1);
}//t_add($$,svm_evala);t_add($$,$2->n);}

| wordset item %prec WORDSET
{
  //cope with 'parent->...'
  if($1==6){
	$$=newnew (justlist);
	$$->jl=$2->jl;
	t_add($$->jl,svm_setp);
	$$->jl->taint();
	$$->jl->wordset=1; 
  }
    else

    {
		$$=newnew (justlist);
		$$->jl=$2->jl;
		t_add($$->jl,svm_sets);
		t_add($$->jl,$1);
		$$->jl->taint();
		$$->jl->wordset=1;
	}

}
| wordfrom item %prec WORDSET
{   //cope with parent<-...
    if($1==6){
		$$=newnew (justlist);
		$$->jl=$2->jl;
		t_add($$->jl,svm_setp);
		$$->jl->taint2();
		$$->jl->wordset==1;
	}
    else {
		$$=newnew (justlist);
		$$->jl=$2->jl;
		t_add($$->jl,svm_setl);
		t_add($$->jl,$1);
		$$->jl->taint2();
		$$->jl->wordset=1;
	}//was setf
}
;

wordlist: word %prec INITIAL_WORD {
	$$=newnew (justlist);
	$$->jl=newtlist;
	primchek($$->jl,evals,$1)//t_add($$,svm_evals);t_add($$,$1);
	$$->jl->extractos=1;
}
| word_q %prec INITIAL_WORD {
	$$=newnew (justlist);
	$$->jl=newtlist;
    if($1==3||$1==6){
	    t_add($$->jl,svm_pevals);
        t_add($$->jl,NG($1+6));
	}
    else {
        t_add($$->jl,svm_nevals);
        t_add($$->jl,$1);
    }
    $$->jl->extractos=1;
}

| word wl %prec INITIAL_WORD {
	$$=newnew (justlist);
    $$->jl=newtlist;
    primchek($$->jl,evals,$1)//t_add($$,svm_evals);t_add($$,$1);
    t_addlist($$->jl,$2->jl);
    $$->jl->extractos=1;
}
| word_q wl %prec INITIAL_WORD {
	$$=newnew (justlist);
	$$->jl=newtlist;
    if($1==3||$1==6){
	    t_add($$->jl,svm_pevals);
        t_add($$->jl,NG($1+6));
    }
	else {
        t_add($$->jl,svm_nevals);t_add($$->jl,$1);
    }
	t_addlist($$->jl,$2->jl);
	$$->jl->extractos=1;
}
| wl_not_word_at_start {
	$$=newnew (justlist);
	$$->jl=$1->jl;
}
;

wl_not_word_at_start: literal %prec INITIAL_WORD {
	$$=newnew (justlist);
	$$->jl=$1->jl;
}
| literal wl %prec INITIAL_WORD {
	$$=newnew (justlist);
	$$->jl=$1->jl;
	t_addlist($$->jl,$2->jl);
}
;

wl: wl_item  {
	$$=newnew (justlist);
	$$->jl=$1->jl;
}
| wl wl_item  {
	$$=newnew (justlist);
	$$->jl=$1->jl;
	t_addlist($$->jl,$2->jl);
}//!!!!!!!
;
wl_item: word {
	$$=newnew (justlist);
	$$->jl=newtlist;
    primchek($$->jl,eval,$1)}//t_add($$,svm_eval);t_add($$,$1);}
| word_q {
	$$=newnew (justlist);
	$$->jl=newtlist;
    if($1==3||$1==6){
	    t_add($$->jl,svm_peval);
		t_add($$->jl,NG($1+6));
	}
    else {
		t_add($$->jl,svm_neval);
		t_add($$->jl,$1);
	}
}
| literal {
	$$=newnew (justlist);
	$$->jl=$1->jl;
}
;




literal:	  LB items2 RB {
	$$=newnew (justlist);
	$$->jl=$2->jl;
}
| LCB object_core RCB {
	$$=newnew (justlist);
	$$->jl=newtlist;
    t_add($$->jl,svm_obj);
	t_addlist($$->jl,$2->jl);
}
| LSB object_core RSB {
	$$=newnew (justlist);
	$$->jl=newtlist;
    t_add($$->jl,svm_block);
	t_addlist($$->jl,$2->jl);
}
| LITERAL_STRING {
	char* temp;
	$$=newnew (justlist);
	$$->jl=newtlist;
    t_add($$->jl,svm_str);
	makestring(temp,string_buf);
    t_add($$->jl,temp);
}//was makestring3 temp,yytext
| LITERAL_FLOAT {
	$$=newnew (justlist);
	$$->jl=newtlist;
    t_add($$->jl,svm_float);
	t_addf($$->jl,(float)(STRTOD(yytext,0)));
}
| LITERAL_DEC  {
	$$=newnew (justlist);
 	$$->jl=newtlist;
    t_addst($$->jl,svm_int);
	t_addst($$->jl,(size_t)STRTOUL(yytext,0,10));
	//$$->jl->print();
}
| LITERAL_BIN {
	$$=newnew (justlist);
	$$->jl=newtlist;
	t_addst($$->jl,svm_int);
	t_addst($$->jl,strtoul(yytext+2,0,2));
}
| LITERAL_HEX {
	$$=newnew (justlist);
	$$->jl=newtlist;
	t_addst($$->jl,svm_int);
	t_addst($$->jl,strtoul(yytext+2,0,16));
}
| LITERAL_FLOAT_NEG {
	$$=newnew (justlist);
	$$->jl=newtlist;
    t_add($$->jl,svm_float);
    t_addf($$->jl,(float)(STRTOD(yytext,0)));
}
| LITERAL_DEC_NEG {
	$$=newnew (justlist);
	$$->jl=newtlist;
    t_add($$->jl,svm_int);
	t_add($$->jl,(size_t)STRTOL(yytext,0,10));
}
| LSB RSB {
	$$=newnew (justlist);
	$$->jl=newtlist;
	t_add($$->jl,svm_block);
}
| LCB RCB {
	$$=newnew (justlist);
	$$->jl=newtlist;
	t_add($$->jl,svm_obj);
}
;

word: AWORD {$$=lookup(yytext)+2;}

| AWORD_D {$$=lookup(yytext+1)+1;}
;
word_q: AWORD_Q {$$=lookup(yytext+1)+2;}
| AWORD_Q_D {$$=lookup(yytext+2)+1;}
|   KEYWORD_Q {char* temp;
               makestring_strip_ends(temp,yytext);
               $$=lookup(temp);}
|   SYMBOL_Q {$$=lookup(yytext+1)+2;}
;



wordfrom: WORDFROM {$$=makestring_from();}
| WORDFROM_Q {$$=makestring_from_q();}
| WORDFROM_K {$$=makestring_from_k();}
| WORDFROM_K_Q {$$=makestring_from_k_q();}
;

wordset: WORDSET {$$=makestring_set();}
	| WORDSET_Q {$$=makestring_set_q();}
| WORDSET_K {$$=makestring_set_k();}
| WORDSET_K_Q {$$=makestring_set_k_q();}


;




symbol: SYMBOL {$$=lookup(yytext)+2;}
;

keyword: KEYWORD {char* temp;
    $$=newnew (numandstring);
    makestring_strip_last(temp,yytext);

    $$->n=lookup(temp);makestring($$->s,yytext);}
;
keyword2: KEYWORD2 {
    char* temp;
    makestring_strip_last(temp,yytext);
    //temp[strlen(temp)-1]=':';
    $$=newnew (numandstring);
    $$->n=lookup(temp);makestring($$->s,yytext);}
;





%%



int yyerror(char* s){
    pen_red
    svmprint("%s. All input discarded!\n",s);
    pen_nor
	return 0;
}

main(int argc,char**argv){

//++argv;--argc;

yyin=fopen("r7","r");


//yydebug=1;

initruntime();
execute_interp();
//yyparse();

};


