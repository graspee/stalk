// [!] primitives work on the object containing the method itself, not a copy.
// [!] if using a multi-arg method primitive. remember the args are on the stack
//         (in reverse order).

//it's another global variable, kids!
size_t num_prims=0;

struct stat* getfileinfo(char* name);



#define newint(x) object x; \
    initobject(x);       \
    x->parent=refobj(integer); \
    x->isnamed=1;\
    x->name=(char*)CSaninteger
#define newint_nodeclr(x)\
    initobject(x);       \
    x->parent=refobj(integer); \
    x->isnamed=1;\
    x->name=(char*)CSaninteger

#define newthing(x) object x; \
    initobject(x); \
    x->isnamed=1;   \
    x->parent=OBJ;

#define newfloat(x) object x;\
  initobject(x);       \
   x->parent=refobj(float); \
   x->isnamed=1;\
   x->name=(char*)CSafloat

#define xnewintfrom(arg)\
    initobject(x);\
    x->parent=refobj(integer); \
    x->isnamed=1;\
    x->value.d=arg;\
    x->name=(char*)CSaninteger


#define newstring(x) object x; \
    initobject(x);       \
    x->parent=refobj(string); \
    x->isnamed=1;\
    x->name=(char*)CSastring

#define newstring_nodeclr(x)\
    initobject(x);       \
    x->parent=refobj(string); \
    x->isnamed=1;\
    x->name=(char*)CSastring

#define NAME theobject->name
#define PARENT theobject->parent
#define PARENTNAME theobject->parent->name
#define OBJ theobject
#define OBJVAL ((size_t)(theobject->value.d))
#define OBJVALAS (theobject->value.d)
#define lOBJVAL (theobject->value.d)
#define sOBJVAL (signed int)(theobject->value.d)
#define OBJVALF theobject->value.f
#define ARG object arg=ocast(glstack.pop());//latestarg
#define GETARG arg=ocast(glstack.pop());
#define ARGNAME arg->name
#define ARGVAL (arg->value.d )
#define ARGVALVP (arg->value.vp)
#define OARGVALVP ARGVALVP//ocast?
#define OARGVAL ARGVAL//ocast
#define CARGVAL (arg->value.c )
//#define CARGVAL ((char*)(ARGVAL))
//#define ARGVAL latestarg->value.d
#define sARGVAL (signed int)(arg->value.d)
#define ARGVALF (arg->value.f)
//#define ARG theobject->arg
//#define ARGNAME theobject->arg->name
//#define ARGVAL theobject->arg->value

//void (*prim_fn [num_prims] ) (object theobject);//array of primitive functions

#define defprim(x) \
	pierce=lookup(#x)+2;\
	nset(prim_table,pierce,x);

#define defprim2(x,y) \
	pierce=lookup(#x)+2;\
	nset(prim_table,pierce,y);

#define defprim_colon(x) \
	pierce=lookup(#x);\
	nset(prim_table,pierce,x);

#define defprim_colon2(x,y) \
	pierce=lookup(#x);\
	nset(prim_table,pierce,y);



#define primitive(n) void n (object theobject)

#ifndef svm_no_gtk
	#include "gtk_prims.cpp"
	#include "svm_gtk_types.hpp"
#endif

#define linereturnint(x) newint(temp);temp->value.d=(size_t)(x);glstack.push(temp)


primitive(__svmevaluate){
ARG
	char *tough_lil_gecko;
	struct yy_buffer_state *baby_deathclaw;
    object temp;
    t_list diditwork;
    int diw;
     
	initobject(temp);
	temp->name=(char*)CStemp;
	temp->isnamed=1;
	temp->parent=OBJ;
	tough_lil_gecko = CARGVAL;

	baby_deathclaw = (yy_buffer_state*)(yy_scan_string(tough_lil_gecko));
	diw=(yyparse());
    
	if(diw==1){glstack.push(refobj(void));}
	else{
                diditwork=reinterpret_cast<t_list>(&diw);
                obj_evalset(temp,diditwork);
		temp->instr[0].d--;
		run(temp,temp);
		//new_runx(temp,theobject);
		//glstack.push(temp);
	}

}

primitive(__console_readline){
    newstring(x);
    x->value.d=(size_t)(readline(0));
    glstack.push(x);
}
primitive(__console_readline_prompt){
ARG   
	newstring(x);
    x->value.d=(size_t)(readline(( char*)(ARGVAL)));
    glstack.push(x);
}

primitive(timenow){
    time_t now;
    newint(glok);
    glok->value.d=time(0);
    glstack.push(glok);
}

primitive(__integer_astime){
    object temp,x;
    struct tm* nowb=localtime((time_t*)(&lOBJVAL));

    initobject(temp);
    temp->parent=refobj(time);
    temp->isnamed=1;
    temp->name=(char*)CSatime;

    xnewintfrom(nowb->tm_sec);
    temp->sets(refmsg(sec),x);
    xnewintfrom(nowb->tm_min);
    temp->sets(refmsg(min),x);
    xnewintfrom(nowb->tm_hour);
    temp->sets(refmsg(hour),x);
    xnewintfrom(nowb->tm_mday);
    temp->sets(refmsg(day),x);
    xnewintfrom(nowb->tm_mon);
    temp->sets(refmsg(mon),x);
    xnewintfrom(nowb->tm_year);
    temp->sets(refmsg(year),x);
    xnewintfrom(nowb->tm_wday);
    temp->sets(refmsg(wday),x);
    xnewintfrom(nowb->tm_yday);
    temp->sets(refmsg(yday),x);
    xnewintfrom(nowb->tm_isdst);
    temp->sets(refmsg(dst),x);

    glstack.push(temp);
}





primitive(__name){
    newint(tl);
	newstring(unicorn);
    unicorn->value.d=(size_t)NAME;
	tl->value.d=STRLEN(NAME);
    unicorn->sets(refmsg(length),tl);
	glstack.push(unicorn);
}

primitive(__stalk_equals){
    ARG
	glstack.push((OBJ->statics==arg->statics)?refobj(true):refobj(false));
}
//primitive(__stalk_nequal2){
//    glstack.push((OBJ->local_message_table!=ARG->local_message_table)?refobj(true):refobj(false));
//}
primitive(__run_colon){
ARG
	//object temp=arg;
	//printf("LEEMOOR running %s as %s (%s)\n",temp->name,OBJ->name,OBJ->self->name);
	
	new_runx(arg,OBJ);
	//run(temp,OBJ);
}
primitive(__run_colon_with){
	object ss[1];
	object rec;
	ss[0]=ocast(glstack.pop());
	rec=ocast(glstack.pop());
	//new_runx_with(rec,OBJ,1,ss);
	run_with(rec,OBJ,1,ss);
}
primitive(__run_colon_with_with){
	object ss[2];
	object rec;
	ss[0]=ocast(glstack.pop());
	ss[1]=ocast(glstack.pop());
	rec=ocast(glstack.pop());
	//new_runx_with(rec,OBJ,2,ss);
	run_with(rec,OBJ,2,ss);
}

primitive(self){

    if(actualobj->isnamed){run(OBJ,OBJ);}
    else{
        while(!actualobj->isnamed){actualobj=actualobj->parent;}
        run(actualobj->self,actualobj);
    }
}
primitive(quote_self){
//printf("[QUOTE_SELF: %s %s]",actualobj->name,OBJ->name);
if(actualobj->isnamed){glstack.push(OBJ);}
    else{
        while(!actualobj->isnamed){actualobj=actualobj->parent;}
        glstack.push(actualobj->self);
    }

}
#ifdef svm_tracing
primitive(selfD){
    if(actualobj->isnamed){run(OBJ,OBJ);}
    else{
        while(!actualobj->isnamed){
        pen_red
        svmprint("    %s is block-trying parent (%s)\n",actualobj->name,actualobj->parent->name);
        pen_nor
            actualobj=actualobj->parent;
        }
        run(actualobj->self,actualobj);
    }
}
primitive(quote_selfD){
if(actualobj->isnamed){glstack.push(OBJ);}
    else{
        while(!actualobj->isnamed){
            actualobj=actualobj->parent;
            pen_red
                svmprint("    %s is block-trying parent (%s)\n",actualobj->name,actualobj->parent->name);
            pen_nor
        }
        glstack.push(actualobj->self);
    }
}
#endif

primitive(parent){
	run(PARENT,PARENT);
}

primitive(tron){
#ifdef svm_tracing
    if(glTrace==1){
		svmprint("Already tracing.\n");
		glstack.push(refobj(false));
	} else {
		svmprint("Trace on!\n");
		glTrace=1;
		glstack.push(refobj(true));
	}
#else
    svmprint("Tracing not available.\n");
    glstack.push(refobj(void));
#endif
}
primitive(troff){
#ifdef svm_tracing
    if(glTrace==0){
		svmprint("But I'm not tracing!.\n");
		glstack.push(refobj(false));
	} else {
		svmprint("Trace off!\n");
		glTrace=0;
		glstack.push(refobj(true));
	}
#else
    svmprint("Tracing not available.\n");
    glstack.push(refobj(void));
#endif
}

primitive(quote_parent){
    glstack.push(PARENT);
}




primitive(__string_minus){
ARG
	char* find;
     char* from;
     char* to;
     char* save;
    newstring(temp);

    find=STRSTR(OBJVAL,ARGVAL);
    if(find==NULL){
        temp->value.d=(size_t)(my_malloc(1+STRLEN(OBJVAL)));
        MEMCPY(temp->value.d,OBJVAL,STRLEN(OBJVAL));
        glstack.push(temp);return;
    }
    else{

        temp->value.d=(size_t)(my_malloc(1+STRLEN(OBJVAL)-STRLEN(ARGVAL)));
        to=(char*)(temp->value.d);
        for(from=(char*)OBJVAL;from<find;from++)*to++=*from;
        from+=STRLEN(ARGVAL);
        for(;*from!=0;from++)*to++=*from;

        find=STRSTR(temp->value.d,ARGVAL);
        if(find==NULL){glstack.push(temp);return;}
        else {
        flip:
            save=(char*)(temp->value.d);
            temp->value.d=(size_t)(my_malloc(1+STRLEN(save)-STRLEN(ARGVAL)));
            to=(char*)(temp->value.d);
            for(from=save;from<find;from++)*to++=*from;
            from+=STRLEN(ARGVAL);
            for(;*from!=0;from++)*to++=*from;

            find=STRSTR(temp->value.d,ARGVAL);
            if(find==NULL){glstack.push(temp);return;}
            else goto flip;
        }
    }
}
primitive(__string_minus_minus){
ARG
	char* find;
     char* from;
     char* to;
     char* save;
     char* temp;

again:
    find=STRSTR(OBJVAL,ARGVAL);
    if(find==NULL){
        glstack.push(OBJ);return;
    }
    else{

        temp=(char*)(my_malloc(1+STRLEN(OBJVAL)-STRLEN(ARGVAL)));
        to=temp;
        for(from=(char*)(OBJVAL);from<find;from++)*to++=*from;
        from+=STRLEN(ARGVAL);
        for(;*from!=0;from++)*to++=*from;

        lOBJVAL=(size_t)temp;

        goto again;

    }
}
//primitive(__filename_from_string){
//}

primitive(__string_find){
ARG   
	object temp;
    register  char* t1;
    t1=STRSTR(OBJVAL,ARGVAL);
    if(t1==NULL){glstack.push(refobj(void));}
    else{
        initobject(temp);
        temp->parent=refobj(integer);
        temp->value.d=(size_t)(1+t1-OBJVAL);
        glstack.push(temp);
    }


}







primitive(__string_multiply){
ARG
	register size_t t1;
    register size_t t2;
    register size_t t3;
    newstring(temp);
    t1=STRLEN(OBJVAL);
    t2=1+(t1*ARGVAL);
    temp->value.d=(size_t)(my_malloc( t2 ));
    for(t3=temp->value.d;t3<-1+(temp->value.d)+t2;t3+=t1)MEMCPY(t3,OBJVAL,t1);
    glstack.push(temp);
}
primitive(__string_multiply_multiply){
ARG   
	register size_t t1;
    register size_t t2;
    register size_t t3;
    char* temp;
    t1=STRLEN(OBJVAL);             //t1 is num of chars in str
    t2=1+(t1*ARGVAL);//t2 is length of stringstring
    temp=(char*)(my_malloc( t2 ));
    for(t3=(size_t)temp;t3<(size_t)(-1+temp+t2);t3+=t1)MEMCPY(t3,OBJVAL,t1);
    lOBJVAL=(size_t)temp;
    glstack.push(OBJ);
}

primitive(__string_plus){
	register size_t t1;
    register size_t t2;
	ARG
    newstring(temp);
    t1=STRLEN(OBJVAL);
    t2=STRLEN(arg->value.d);
    temp->value.d=(size_t)(my_malloc(1+t1+t2));
    MEMCPY(temp->value.d,OBJVAL,t1);
    MEMCPY(temp->value.d+t1,arg->value.d,t2+1);
    glstack.push(temp);
}
primitive(__string_plus_plus){
    register size_t t1;
    register size_t t2;
	register object arg;
    char* temp;
	arg=ocast(glstack.pop());
    t1=STRLEN(OBJVAL);
    t2=STRLEN(arg->value.d);
    temp=(char*)(my_malloc(1+t1+t2));
    MEMCPY(temp,OBJVAL,t1);
    MEMCPY(temp+t1,arg->value.d,t2+1);
    lOBJVAL=(size_t)temp;
    glstack.push(OBJ);
}


primitive(__integer_print){
        svmprint("%d",OBJVAL);
		glstack.push(OBJ);
}
primitive(__float_print){
  svmprint("%.2f",OBJVALF);
  glstack.push(OBJ);
}

primitive(__string_print){
    svmprint((char*)(OBJVAL));
	glstack.push(OBJ);
}

primitive(__malloc){
ARG
	linereturnint(my_calloc(ARGVAL));
}
primitive(__intsize){
	linereturnint(sizeof(size_t));
}
primitive(__getobjfrom){
ARG
	object temp=ocast(*((void**)ARGVAL));
	if(temp==0)glstack.push(refobj(void));
	else
	glstack.push(temp);
}
primitive(__putobj_to){
	object a=ocast(glstack.pop());
	void* b=glstack.pop();
	*((void**)(a->value.d))=b;
       glstack.push (&a);
}
//FLOAT COMPARISONS

primitive(__float_lessthan){
ARG
	glstack.push((OBJVALF<ARGVALF)?refobj(true):refobj(false));
}
primitive(__float_lessthan_equal){
ARG 
	glstack.push((OBJVALF<=ARGVALF)?refobj(true):refobj(false));
}
primitive(__float_greaterthan_equal){
ARG   
	glstack.push((OBJVALF>=ARGVALF)?refobj(true):refobj(false));
}
primitive(__float_greaterthan){
ARG   
	glstack.push((OBJVALF>ARGVALF)?refobj(true):refobj(false));
}
primitive(__float_equals){
ARG   
	glstack.push((OBJVALF==ARGVALF)?refobj(true):refobj(false));
}
primitive(__float_nequal){
    ARG
	glstack.push((OBJVALF!=ARGVALF)?refobj(true):refobj(false));
}

//FLOAT MATHS

primitive(__float_add){
ARG 
	newfloat(temp);temp->value.f=OBJVALF+ARGVALF;glstack.push(temp);
}
primitive(__float_minus){
ARG 
	newfloat(temp);temp->value.f=OBJVALF-ARGVALF;glstack.push(temp);
}
primitive(__float_divide){
  ARG
	newfloat(temp);temp->value.f=OBJVALF/ARGVALF;glstack.push(temp);
}
primitive(__float_multiply){
ARG 
	newfloat(temp);temp->value.f=OBJVALF*ARGVALF;glstack.push(temp);
}
primitive(__float_multiply_multiply){
ARG 
	OBJVALF*=ARGVALF;glstack.push(OBJ);
}
primitive(__float_divide_divide){
ARG
	OBJVALF/=ARGVALF;glstack.push(OBJ);
}
primitive(__float_plus_plus){
  ARG
	OBJVALF+=ARGVALF;glstack.push(OBJ);
}
primitive(__float_minus_minus){
  ARG
	OBJVALF-=ARGVALF;glstack.push(OBJ);
}

//INTEGER COMPARISONS

primitive(__integer_equals){
   // glstack.push((OBJVAL==ARGVAL)?refobj(true):refobj(false));
	ARG
	glstack.push((OBJVAL==ARGVAL)?refobj(true):refobj(false));
}
primitive(__integer_nequal){
    ARG
	glstack.push((OBJVAL!=ARGVAL)?refobj(true):refobj(false));
}
primitive(__integer_lessthan){
    ARG
	glstack.push((sOBJVAL<sARGVAL)?refobj(true):refobj(false));
}
primitive(__integer_lessthan_equal){
    ARG
	glstack.push((sOBJVAL<=sARGVAL)?refobj(true):refobj(false));
}
primitive(__integer_greaterthan){
    ARG  
	glstack.push((sOBJVAL>sARGVAL)?refobj(true):refobj(false));
}
primitive(__integer_greaterthan_equal){
    ARG
	glstack.push((sOBJVAL>=sARGVAL)?refobj(true):refobj(false));
}
//INTEGER BITWISE
primitive(__mod){
ARG	linereturnint(OBJVAL%ARGVAL);
}
primitive(__shiftl){
	ARG linereturnint(OBJVAL<<ARGVAL);
}
primitive(__shiftr){
	ARG linereturnint(OBJVAL>>ARGVAL);
}

primitive(__integer_and){
    ARG linereturnint(OBJVAL&ARGVAL);
}
primitive(__integer_or){
    ARG linereturnint(OBJVAL|ARGVAL);
}
primitive(__integer_xor){
   ARG  linereturnint(OBJVAL^ARGVAL);
}
primitive(__integer_not){
    linereturnint(~OBJVAL);
}
//to self
primitive(__mods){
	ARG OBJVALAS%=ARGVAL;glstack.push(OBJ);
}
primitive(__shiftls){
ARG	OBJVALAS<<=ARGVAL;glstack.push(OBJ);
}
primitive(__shiftrs){
ARG	OBJVALAS>>=ARGVAL;glstack.push(OBJ);
}

primitive(__integer_and_and){
ARG    OBJVALAS&=ARGVAL;glstack.push(OBJ);
}
primitive(__integer_or_or){
   ARG OBJVALAS|=ARGVAL;glstack.push(OBJ);
}
primitive(__integer_xor_xor){
   ARG OBJVALAS^=ARGVAL;glstack.push(OBJ);
}
primitive(__integer_not_not){
    ARG OBJVALAS=~OBJVAL;glstack.push(OBJ);
}
//IARG NTEGER MATHS

primitive(__integer_multiply){
  ARG  linereturnint(OBJVAL*ARGVAL);
}
primitive(__integer_divide){
 ARG   linereturnint(OBJVAL/ARGVAL);
}
primitive(__integer_add){
 ARG   linereturnint(OBJVAL+ARGVAL);
}
primitive(__integer_minus){
  ARG  linereturnint(OBJVAL-ARGVAL);
}
primitive(__integer_plus_plus){
ARG	lOBJVAL += ARGVAL;glstack.push(OBJ);
}
primitive(__integer_minus_minus){
ARG	lOBJVAL -= ARGVAL;glstack.push(OBJ);
}
primitive(__integer_multiply_multiply){
ARG	lOBJVAL *= ARGVAL;glstack.push(OBJ);
}
primitive(__integer_divide_divide){
ARG	lOBJVAL /= ARGVAL;glstack.push(OBJ);
}

//STRING COMPARISONS

primitive(__string_equals){
 ARG   glstack.push((STRCMP(OBJVAL,ARGVAL)==0)?refobj(true):refobj(false));
}
primitive(__string_lessthan){
 ARG   glstack.push((STRCMP(OBJVAL,ARGVAL)<0)?refobj(true):refobj(false));
}
primitive(__string_greaterthan){
ARG    glstack.push((STRCMP(OBJVAL,ARGVAL)>0)?refobj(true):refobj(false));
}
primitive(__string_lessthan_equal){
 ARG    glstack.push((STRCMP(OBJVAL,ARGVAL)<=0)?refobj(true):refobj(false));
}
primitive(__string_greaterthan_equal){
  ARG glstack.push((STRCMP(OBJVAL,ARGVAL)>=0)?refobj(true):refobj(false));
}
primitive(__string_nequal){
    ARG glstack.push((STRCMP(OBJVAL,ARGVAL)!=0)?refobj(true):refobj(false));
}

/*primitive(__string_length){
    newint(temp);temp->value.d=STRLEN(OBJVAL);glstack.push(temp);
}*/

primitive (__getval){
	linereturnint(OBJVAL);
}
primitive(__setval){
ARG
	lOBJVAL=ARGVAL;
	glstack.push(OBJ);
}


primitive(__stalk_exit){
    exit(0);
}
primitive(__stalk_exit_val){
 ARG   exit(ARGVAL);
}

primitive(gcstats){
#ifdef svm_tracing
	if(glGCStats==1){
		svmprint("GC Stats already on.\n");
		glstack.push(refobj(false));
	}
	else{
		svmprint("GC Stats enabled.\n");
		glGCStats=1;
		glstack.push(refobj(true));
	}
#else
	svmprint("Stats not available.\n");
	glstack.push(refobj(false));
#endif
}
primitive(gcstatsoff){
#ifdef svm_tracing
	if(glGCStats==1){
		svmprint("GC Stats disabled.\n");
		glGCStats=0;
		glstack.push(refobj(true));
	
	}
	else{
		svmprint("GC Stats already off.\n");	
		glstack.push(refobj(false));
	}
#else
	svmprint("GC Stats not available.\n");
	glstack.push(refobj(false));
#endif
}
primitive (stats){
#ifdef svm_tracing
	if(glStats==1){
		svmprint("Stats already on.\n");
		glstack.push(refobj(false));
	}
	else{
		svmprint("Stats enabled.\n");
		glStats=1;
		glstack.push(refobj(true));
	}
#else
	svmprint("Stats not available.\n");
	glstack.push(refobj(false));
#endif
}
primitive(statsoff){
#ifdef svm_tracing
	if(glStats==1){
		svmprint("Stats disabled.\n");
		glStats=0;
		glstack.push(refobj(true));
	
	}
	else{
		svmprint("Stats already off.\n");	
		glstack.push(refobj(false));
	}
#else
	svmprint("Stats not available.\n");
	glstack.push(refobj(false));
#endif
}
/*primitive(__memalloc){
	newint(temp);
	temp->value.d=my_malloc(ARGVAL);
	glstack.push(temp);
}*/
primitive(setf){
    //MEMCPY(OBJ,ARG,sizeof(struct objectx));
ARG
    shallowcopy_noinit(OBJ,arg);
	glstack.push(OBJ);

}
primitive(__memcopy_from_to){
	
	object to,from,num;
	to=ocast(glstack.pop());
	from=ocast(glstack.pop());
	num=ocast(glstack.pop());
	MEMCPY(to->value.d,from->value.d,num->value.d);
	glstack.push(to);
}
primitive(__putchar_at){
	//objval=char
	//argval=loc
	object a1=ocast(glstack.pop());
	object a2=ocast(glstack.pop());
	*((char*)(a1->value.d))=(char)(a2->value.d);
	glstack.push(OBJ);

}
primitive(__getchar){
	object a1;
	newint(x);
	a1=ocast(glstack.pop());
	x->value.d=(size_t)(   * ( (char*)((a1->value.d)) )   );
	glstack.push(x);

}
primitive(__file_lock_mode){
//arg1=file*
	//arg2=mode as string
	
	//return file* or 0=fail
	
	char* mode,*filename;
	newint(temp);
	ARG

	mode=CARGVAL;
	filename=CARGVAL;
	
	temp->value.d=(size_t)fopen(filename,mode);
	glstack.push(temp);
	
}
primitive(__file_unlock){
//arg1=file*
	ARG
	FILE* f;
	int result;
	f=(FILE*)(ARGVAL);
	result=fclose(f);
	glstack.push(result==0?refobj(true):refobj(false));
}
primitive(__file_raw_read_to_length){
	//args= file*,bufferloc,bufferlen
ARG
	FILE*fpointer;
	size_t bufferlen;
	char* bufferloc,*c;
	bufferlen=ARGVAL;
	bufferloc=CARGVAL;
	

	fpointer=(FILE*)(ARGVAL);
	
	rewind(fpointer);
	for(c=bufferloc;c<bufferloc+bufferlen;c++){*c=fgetc(fpointer);}
	glstack.push(refobj(true));
	
}
primitive(__file_get_length){
ARG	struct stat *xx;
	char*pp;
	newint(temp);
	pp=CARGVAL;
	xx=getfileinfo((char*)pp);
	temp->value.d=xx->st_size;
	glstack.push(temp);
	

}

primitive(__prims){
	for(int f=1;f<num_prims+1;f++){
		printf("[ %d %s %d ]\n",f,getsymbolname(f),nget(prim_table,f));
	}
	glstack.push(refobj(true));
}
struct stat* getfileinfo(char* name){
	struct stat mystatbuffer;
	int result;
	result=stat(name,&mystatbuffer);
	if(result!=0){
		pen_red
		svmprint("Error getting file info for '%s'.",name);
		pen_nor
		return &mystatbuffer;
	}
	else {
		return &mystatbuffer;
	}
}


//primitive(seti){
//	OBJ=ARG;
//	glstack.push(OBJ);
//}
/*primitive(__memfill_with_size_colon){
	//uses 4 byte pattern, size is in bytes
	object w,s;
	size_t* xxx;
	size_t f;
	s=ARG;
	w=ARG;
	f=ARGVAL;
	for(xxx=f;
	xxx<f+s->value.d;
	*(xxx++)=w){
		printf("%d ",xxx);}
	glstack.push(f);


}*/

void __slots(object x){
    pen_yel svmprint("Name:"); pen_nor svmprint("%s\n",x->name);
	pen_yel svmprint("Parent:"); pen_nor svmprint("%s\n",(x->parent==0)?"*none*":(x->parent->name));
    pen_yel svmprint("Value:"); pen_nor svmprint("%d\n",x->value);
    pen_yel svmprint("Self:"); pen_nor svmprint("%s\n",x->self->name);
    pen_yel svmprint("Isnamed:"); pen_nor svmprint("%d\n",x->isnamed);
    pen_yel svmprint("Instr:"); pen_nor svmprint("%d\n",(x->instr)?(x->instr[0].d):((size_t)(x->instr)));
    pen_yel svmprint("Args:"); pen_nor
        if (x->args==0)svmprint("*none*\n");
			else {	MESSAGE f;
                        
			iterate(x->args,MESSAGE,f)
			
                        
                        printsymbolname(f);svmprint(" (%d) ",f);
            enditerate
                        svmprint("\n");}
    pen_yel svmprint("Statics:\n"); pen_nor
   display( x->statics);
	pen_yel svmprint("Locals:\n"); pen_nor
    display(x->locals);
glstack.push(x);
}


size_t __dump_inner(object& x,size_t f,unsigned short int indent){
	size_t d;
	char thisx;
	
	d=x->instr[f].d;
	
	thisx=svm_codes[d-1001].smart_code;
	if(thisx!=900){
		pen_yel
		{ int g;for(g=0;g<indent;svmprint(" ")) {g++;} }
		svmprint ("%s ",svm_codes[d-1001].name);
		pen_nor
		d=x->instr[++f].d;
		switch(thisx){
			case 0:svmprint("\n");f--;break;
			case 1:pen_cyn printsymbolname(d);pen_nor svmprint(" (%d) \n",d);break;
            case 2:svmprint("%d\n",d);break;
            case 3:svmprint("%s\n",d);break;
            case 4:svmprint("[ %d ]\n",d);break;
            case 5:pen_cyn printsymbolname(d); pen_nor svmprint(" (%d) ",d);
				svmprint(",%d\n",x->instr[++f].d);
				break;
            case 6:svmprint("[%d]",d);
                svmprint(",%d\n",x->instr[++f].d);
				break;
		}
	
	}
   return f;         
}
void __dump(object x){
    //the only case we lie about is evalx, since it's not really
    //'evalx with:from;' but 'evalx with:from; 2 19 27'
    //but since the extra numbers are just to speed things up we don't print them

	size_t f;


    if(x->instr==0){svmprint("This object has no code.\n");}
	else
	{

		for(f=1;f<(x->instr[0].d);f++){
		
			
			f=__dump_inner(x,f,8);
					
		}
	}
glstack.push(x);
}

void init_primitives(){
	size_t pierce;//used by defprim

defprim(self);
defprim(parent);
defprim(quote_self);
defprim(quote_parent);

defprim_colon(__setval);
defprim(__getval);
//integer
defprim_colon(__integer_minus);
defprim_colon(__integer_add);
defprim_colon(__integer_multiply);
defprim_colon(__integer_divide);

defprim_colon(__integer_plus_plus);
defprim_colon(__integer_minus_minus);
defprim_colon(__integer_multiply_multiply);
defprim_colon(__integer_divide_divide);

defprim_colon(__integer_lessthan);
defprim_colon(__integer_equals);
defprim_colon(__integer_greaterthan);
defprim_colon(__integer_nequal);
defprim_colon(__integer_lessthan_equal);
defprim_colon(__integer_greaterthan_equal);


defprim_colon(__shiftl);
defprim_colon(__shiftr);
defprim_colon(__shiftls);
defprim_colon(__shiftrs);
defprim_colon(__mod);
defprim_colon(__mods);
defprim_colon(__integer_and);
defprim_colon(__integer_or);
defprim_colon(__integer_xor);
defprim(__integer_not);
defprim_colon(__integer_and_and);
defprim_colon(__integer_or_or);
defprim_colon(__integer_xor_xor);
defprim(__integer_not_not);



defprim(__integer_print);
defprim(__integer_astime);



defprim_colon(__malloc);
defprim_colon(__getobjfrom);
defprim2(__putobj:at;,__putobj_to);


defprim_colon(__stalk_equals);

defprim_colon(__svmevaluate);

defprim_colon(setf);
defprim(__dump);

defprim(__intsize);
defprim(__string_print);
defprim(__string_equals);
defprim(__string_nequal);


defprim_colon(__getchar);
defprim2(__putchar:at;,__putchar_at);

defprim_colon(__string_plus);
defprim_colon(__string_plus_plus);
defprim(__string_multiply);
defprim(__string_multiply_multiply);

defprim2(__memcopy:from;to;,__memcopy_from_to);


defprim(__string_find);
defprim(__string_lessthan);
defprim(__string_greaterthan);
defprim(__string_greaterthan_equal);
defprim(__string_lessthan_equal);
defprim(__string_minus);
defprim(__string_minus_minus);

defprim(tron);
defprim(troff);
defprim(timenow);

defprim(__float_print);
defprim_colon(__float_add);
defprim_colon(__float_minus);
defprim_colon(__float_multiply);
defprim_colon(__float_divide);
defprim_colon(__float_lessthan);
defprim_colon(__float_greaterthan);
defprim_colon(__float_equals);
defprim_colon(__float_nequal);
defprim_colon(__float_lessthan_equal);
defprim_colon(__float_greaterthan_equal);
defprim_colon(__float_plus_plus);
defprim_colon(__float_minus_minus);
defprim_colon(__float_multiply_multiply);
defprim_colon(__float_divide_divide);
defprim(__name);
defprim_colon2(run,__run_colon);
defprim2(run:with;,__run_colon_with);
defprim2(run:with;with;,__run_colon_with_with);
defprim(__console_readline_prompt);
defprim(__console_readline);
defprim(__slots);
defprim(__stalk_exit);
defprim(__stalk_exit_val);


defprim(gcstats);
defprim(gcstatsoff);
defprim(stats);
defprim(statsoff);

defprim_colon(__file_get_length);
defprim2(__file_lock:mode;,__file_lock_mode);
defprim_colon(__file_unlock);
defprim2(__file_raw_read:to;length;,__file_raw_read_to_length);
//defprim_colon(__filename_from_string);
//defprim(__listprims);
//gtk stuff
#ifndef svm_no_gtk
	
	//set up all the types for gtk
	setup_gtk_types();
	
	defprim_colon(__gui_widget_new)
	defprim2(__gui_propset:value;,__gui_propset_value)
	defprim_colon(__gui_propget)
	defprim(enter_gui_loop)
	defprim(exit_gui_loop)
	defprim(__signal_disconnect)
	defprim(__signal_enable)
	defprim(__signal_disable)
	defprim_colon(__signal_emit)
	defprim2(__gui_signal:do;,__gui_signal_do)
	defprim2(__gui_signal:dowith1arg;,__gui_signal_do_with1arg)
	defprim_colon(__gui_container_add)
	defprim(__gui_widget_show)
	defprim(__gui_widget_hide)
	defprim2(__gui_widget_sizex:sizey;,__gui_widget_sizex_sizey)
	defprim(__gui_text_chars)
	defprim_colon(__gui_ctree_insert_node)
	defprim2(__gui_ctree_insert_node:parent;sibling;,__gui_ctree_insert_node_specific);
	defprim_colon(__gui_ctree_setexpanderstyle)
	defprim_colon(__gui_ctree_setlinestyle)
	defprim_colon(__gui_ctree_setindent)
#endif
defprim(__prims);
//after all the defprims we set num_prims=current_message
//we can later compare and if x<num_prims then it is a primitive
num_prims=currentmessage;
//__prims(0);
}

