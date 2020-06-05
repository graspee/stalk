void init_svm_codes();

void initruntime(){

#ifndef svm_no_gtk
	gtk_init(0,0);//no gtk_exit as yet
#endif

	currentmessage=1;
	init_primitives();
	init_svm_codes();      
}





#define adjust3(a) (((a-1)/3)+1) //gives you the base number- eg 1-3 is 1,4-6 is 2

//#define ocast(x) (static_cast<object>(x))

/*
#define obj_setl(a,b,c)  ocast(a) ->locals->set(b,(void*)(c))
#define obj_sets(a,b,c)  ocast(a) ->statics->set(b,(void*)(c))
#define obj_getl(a,b)    ocast(a) ->locals->get(b)
#define obj_findl(a,b)   ocast(a)->locals->find(b)
#define obj_gets(a,b)    ocast(a) ->statics->get(b)
#define obj_finds(a,b)   ocast(a)->statics->find(b)
*/


#define initobject(x) x=newobject;x->locals=newtree;x->statics=newtree;x->self=x //IDEA commented this out


//#define shallowcopy(a,b) a=object(b);


inline object shallowcopy(object b) {
	object a;
	initobject(a);
	a->instr=b->instr;
	a->parent=b->parent;
	a->locals=b->locals;
	a->statics=b->statics;
	a->value=b->value;
	a->self=b->self;
	a->args=b->args;
	a->isnamed=b->isnamed;
	a->name=b->name;

	return a;
}

#define shallowcopy_noinit(a,b) \
	a->instr=b->instr;\
	a->parent=b->parent;\
	a->locals=b->locals;\
	a->statics=b->statics;\
	a->value=b->value;\
	a->self=b->self;\
	a->args=b->args;\
	a->isnamed=b->isnamed;\
	a->name=b->name;

//#define shallowcopy2(a,b) memcpy(a,b,sizeof(struct objectx))




void* display(tree t){
    if(t->key==0){svmprint("    *empty*\n");return 0;}
	else {
            pen_cyn svmprint("    ");printsymbolname(t->key);pen_nor
            svmprint("  %s\n",ocast(t->data)->name);
            if(t->left!=0)display(t->left);
            if(t->right!=0)display(t->right);

	}
}



#define msg_send(a,b){\
    svmprint("    Sending message ");\
    printsymbolname(b);\
    svmprint(" to %s\n", ocast(a)->name);\
    }

#define msg_inst(a,b){ pen_cyn \
    svmprint("        %s ",a);printsymbolname(b);svmprint("\n");\
    pen_nor }








//EVIL GLOBALS!

object actualobj;//latestarg
//list visited;




object create_new_object(char* name,char* parent,char* myargs...);




void execute_interp(void);
void obj_evalset(object, t_list);
void obj_evalset2(t_list);
object obj_eval2(object,size_t);
void run2(object);

inline void voidanyargs(object x){
	if( x->args!=0 ){
		MESSAGE f;

		iterate(x->args,MESSAGE,f)
	
                
                    x->setl(f,refobj(void));
    
		enditerate
    }
}



//#define solorun(x) run2(x)



//[print] is EVALS print

//[(+0)print] is INT 0,EVALXS +,EVAL print



//using this for "run:", [print] works, [(+1)print] fails


//i.e. run tempblok as f
//create a copy of tempblock with a blank message table, set its "self" to be f, and run!
inline void run(object o,object current){
    if(o->instr==0){glstack.push(o);}
    else {object leem;leem=shallowcopy(o);
    leem->self=current;
    leem->locals=newtree;
	voidanyargs(leem);
    run2(leem);
		o->parent=leem->parent;
		o->value=leem->value;
}
}
inline void run_with(object o,object current,size_t numargs,object stackstore[]) {

if(o->instr==0){glstack.push(o);}
else {
	object leem;size_t num;
	leem=shallowcopy(o);
	leem->self=current;
	leem->locals=newtree;
	num=numargs;
	if(leem->args!=0){
		MESSAGE feena;
		while(num>leem->args->numberin){num--;}
		leem->args->it=leem->args->start; 
		while(leem->args->it!=leem->args->end) { 
			leem->args->it=leem->args->it->next; 
			feena=(MESSAGE)(leem->args->it->data.st);
			if(num>0){leem->setl(feena,stackstore[numargs-num]);num--;}
			else {leem->setl(feena,refobj(void));}
		}
	}
	run2(leem);
	o->parent=leem->parent;
	o->value=leem->value;
}
}
//#define run(o,current) new_run(o,current)

//using this method [print] fails, [(+1)print] works

//create a copy of f with a blank message table, set its instructions to be tempblok's, and run
//after run, copy certain bits back into the f
inline void new_runx(object o,object current){
    if(ocast(o)->instr==0){glstack.push(o);}
    else {object leem;leem=shallowcopy(current);
 //   leem->local_message_table=(treenodex*)newnew(treenodex);
	leem->instr=o->instr;
	leem->self=leem;
	voidanyargs(leem);
    run2(leem);
	current->parent=leem->parent;
	current->value=leem->value;
	}
}
inline void new_runx_with(object o,object current,size_t numargs,object stackstore[]) {

if(ocast(o)->instr==0){glstack.push(o);}
else {
	object leem;size_t num;
	leem=shallowcopy(current);
//	leem->local_message_table=(treenodex*)(newnew(treenodex));
	leem->instr=o->instr;leem->args=o->args;//2nd part is new
	leem->self=leem;
	num=numargs;
	if(leem->args!=0){
		MESSAGE feena;
		while(num>leem->args->numberin){num--;}
		leem->args->it=leem->args->start; 
		while(leem->args->it!=leem->args->end) { 
			leem->args->it=leem->args->it->next; 
			feena=(MESSAGE)(leem->args->it->data.st);
			if(num>0){leem->setl(feena,stackstore[numargs-num]);num--;}
			else {leem->setl(feena,refobj(void));}
		}
	}
	//else {while(num>0){glstack.pop();num--;}}
	run2(leem);
	current->parent=leem->parent;
	current->value=leem->value;
	//is this putting something on the stack properly?
	//probably is- stack fault due to taking arg twice before...
}
}
//#define new_runx(a,b) run(a,b)
//^ problem solved- it was the missing leem->self = leem that fscked it up!
//#define run(a,b) new_runx(a,b)








#include "primitives.cpp"





object create_new_object(char* name,char* parent,char* myargs...){
	object temp;
	initobject(temp);
	temp->parent=object_stalk;//lookup(parent);
    temp->isnamed=1;
    temp->name=name;
	
	 va_list vl;
    int i;

    //  szTypes is the last argument specified; all
    //   others must be accessed using the variable-
    //   argument macros.
    va_start( vl, parent );

    
	char* tempstr;
	MESSAGE tempmsg;
	void* tempansa;
	char* temptype;
	object tempsubobj;

	while(1){
		tempstr=va_arg(vl,char*);
		if(tempstr==0)break;
		temptype=va_arg(vl,char*);
		tempmsg=lookup(tempstr)+2;
		tempansa=va_arg(vl,void*);
		switch(*temptype){
		case 'n':
			newint_nodeclr(tempsubobj);
			tempsubobj->value.d=(size_t)(tempansa);
			break;
		case 's':
			newstring_nodeclr(tempsubobj);
			tempsubobj->value.d=(size_t)(tempansa);
			break;
		}
		temp->sets(tempmsg,tempsubobj);
	}


    va_end( vl );

	return temp;
}



/************************************************
*						*
*	execute_interp( t_list )			*
*						*
*	Initializes stuff then runs the code obtained	*
*	from the parser. When we have a proper CLI	*
*	we will have to separate this out...		*
*						*
************************************************/

void execute_interp()
{				//was (t_list l)
    t_list diditwork;
    int diw;
    
	nil=malloc(1);
	objnil=newobject;

	pen_yel
    svmprint("\nSTALK interpreter v0.01a\nWritten by Graspee\n(c) 2000 Happi Llama Realtech\n");
    pen_cyn


#ifdef svm_tracing
		svmprint("[Tracing available (tron troff stats statsoff gcstats gcstatsoff)]\n");
		glStats=0;
		glGCStats=0;
#ifdef svm_tracefromstart
		glTrace=1;
#else
		glTrace=0;
#endif
#else
		svmprint("[No tracing available]\n");
#endif
#ifdef svm_error_check
    svmprint("[Error checking enabled]\n\n");
#else
    svmprint("[No error checking]\n\n");
#endif
    pen_nor

    /*list aaa,bbb;
    aaa=list::create();
    bbb=list::create();
    aaa->additem(1);
	aaa->additem(2);
    aaa->additem(3);
	
	bbb->additem(7);
	bbb->additem(8);
	bbb->additem(9);

	aaa->print();printf("\n");
	bbb->print();printf("\n");
	aaa->addlist_rev(bbb);
	aaa->print();printf("\n");
*/
	initobject(object_stalk);
    object_stalk->name = getsymbolname(refmsg(stalk));
    object_stalk->isnamed = 1;
    object_stalk->sets( refmsg(stalk), object_stalk);

    //this is a bit scarey because yyparse is defined as returning 'int'
    //hopefully sizeof(int)>=sizeof(void*) on all machines.

    diw=yyparse();

    if(diw==1){pen_red svmprint("Failed to read R7. Exiting.\n(I bet you messed with it, didn't you?)\n");pen_nor exit(1);}
    diditwork=reinterpret_cast<t_list>(diw);
    obj_evalset(object_stalk, diditwork);	//yyparse was l

    //obj_evalset2();

    glstack.push(object_stalk);

    //
    //__dump(object_stalk,0);exit(0);
    //


//run stalk for the first time- which inits the standard library


    run2(object_stalk);


    


    using_history();
	
//#ifndef svm_no_gtk
	//gtk_init(0,0);//no gtk_exit as yet
//#endif

    while (1) {
	char *tough_lil_gecko;
	struct yy_buffer_state *baby_deathclaw;
    slipmeanother:
      
	
	
		pen_pnk
		svmprint(">");fflush(stdout);
		tough_lil_gecko = readline("");
	pen_nor
        add_history(tough_lil_gecko);
        baby_deathclaw = (yy_buffer_state*)(yy_scan_string(tough_lil_gecko));

        diw=yyparse();
        if(diw==1){goto slipmeanother;}
        diditwork=reinterpret_cast<t_list>(diw); //was & not cast part 2
        obj_evalset2(diditwork);
#ifdef svm_tracing
	glMaxDepth=glNumInstr=glNumMessageSends=0;
#endif

    run2(object_stalk);

    svmprint("\n");
#ifdef svm_tracing
	if(glStats==1){
	svmprint("SVM Instructions: %d, Message Sends: %d, Max Depth: %d\n",glNumInstr,glNumMessageSends,glMaxDepth);
	}
//	if(glGCStats==1){
//		pen_yel svmprint("list:\n");pen_nor list::gcstats();
//		pen_yel svmprint("t_list:\n");pen_nor t_list::gcstats();
//		pen_yel svmprint("tree:\n");pen_nor tree::gcstats();
//		pen_yel svmprint("object:\n");pen_nor object::gcstats();
//	}
#endif
	}

}



/************************************************
*						*
*	obj_evalset(object, t_list)			*
*						*
*	Turns the t_list into an array and a number	*
*	of elements then adds to the appropriate	*
*	fields in the object				*
*						*
************************************************/
void obj_evalset(object o, t_list t)
{

    size_t f;
    size_t* d;
    o->instr = (union uftype*)(my_malloc((t->numberin + 1) * (sizeof(size_t))));
    o->instr[0].d = t->numberin + 1;
    d = (size_t*)(o->instr + 1);

    iterate(t,size_t,f)
	
		* d++ = f;
    
	enditerate
	o->args=t->args;
    //if(o->args!=0)svmprint("[argset:%s %d]\n",o->name,t);
}

void obj_evalset2(t_list t)
{

    size_t f;
    size_t* d;
  //  t_list t = yyparse();
    object_stalk->instr = (union uftype*)(my_malloc((t->numberin + 3) * (sizeof(size_t))));
    object_stalk->instr[0].d = t->numberin + 3;
    d = (size_t*)(object_stalk->instr + 1);
	
	iterate(t,size_t,f)
    
		* d++ = f;
    
	enditerate
	d--;

    *d++ = svm_eval;
    *d++ = refmsg(print);
    *d++ = svm_ctos;
	object_stalk->args=t->args;
    //if(object_stalk->args!=0)svmprint("[argset2] \n");
	//this will put the info on args required by stalk into the stalk obj
	//but it won't do much good, since it won't be this object which gets run, in for example, cgi scripts

}

#define ifprimdonow(theobject,themessage) if (themessage < (num_prims + 1)) \
    {(*prim_fn[adjust3(themessage)-1])(theobject);}
#define ifprimdonowS(theobject,themessage) if (themessage < (num_prims + 1)) \
{actualobj=theobject;(*prim_fn[adjust3(themessage)-1])(theobject->self);}
#define ifprimdonowX(theobject,themessage) if (themessage < (num_prims + 1)) \
    {pc+=num;(*prim_fn[adjust3(themessage)-1])(theobject);}
#define ifprimdonowXS(theobject,themessage) if (themessage < (num_prims + 1)) \
    {pc+=num;(*prim_fn[adjust3(themessage)-1])(theobject->self);}


#define ifprimdoerror(theobject,themessage) if (themessage < (num_prims + 1)) {pen_red svmprint("ERROR: attempt to quote primitive!\n"); glstack.push(refobj(void));pen_nor}






//OBJ EVAL2 WAS HERE



#include "svm_fns.cpp"


/************************************************
*						*
*	run(object, object)				*
*						*
*	Runs the eval code in the first object in the	*
*	context of the second object			*
*						*
************************************************/

void run2(object o)
{
    size_t pc;

#ifdef svm_tracing
	glIndent++;
	if(glIndent>glMaxDepth)glMaxDepth=glIndent;
	if(glTrace==1){
		pen_grn
		svmprint("--");
		svmprint(o->name);
		svmprint("--------------------\n");
		pen_nor
	}
#endif

    glstack.push(o);

//	svmprint("HERE\n");
//	for (pc = 1; pc < o->instr[0].d; pc++){
//		printf( "%d",o->instr[pc].d );
//		svmprint( ".");
//	}


    for (pc = 1; pc < o->instr[0].d; pc++) {

#ifdef svm_tracing
		glNumInstr++;
		if(glTrace==1){
//			size_t ffff;
//			ffff=o->instr[1].d;
			__dump_inner(o,pc,glIndent);
//			if (ffff!=o->instr[1].d){cout<<"error";}
		}
#endif

#ifdef svm_error_check
		if (o->instr[pc].d<1001 || o->instr[pc].d>(1000+num_codes)){
			pen_red
			svmprint("Illegal instruction encountered!\n");
			pen_nor
		}
#endif
		(svm_codes[o->instr[pc].d-1001].fn)(o,&pc);

	}

{
   object result;
	result=ocast(glstack.pop());glstack.pop();glstack.push(result);
#ifdef svm_tracing
	glIndent--;
#endif
}

}


