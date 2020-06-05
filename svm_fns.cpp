svmfn(ctos){
	glstack.pop();
}
svmfn(obj){
	object temp;
	initobject(temp);
	temp->parent = object_stalk;
    temp->name = (char*)CStemp;
    temp->isnamed=1;
    glstack.push(temp);
}
svmfn(block){
	object temp;
	initobject(temp);
	temp->parent = o;
    temp->name = (char*)CStempblock;
    glstack.push(temp);
}
svmfn(seteval){
	t_list v;
	object p;
	p=ocast(glstack.peek());
	v=reinterpret_cast<t_list>(o->instr[++*pc].vp);
	//oo=ocast(glstack.peek());
	obj_evalset(p, v);//this d was a t- what gives?
}
svmfn(setl){
	object temp;
    size_t xtra;
	//temp = object::create();
	//memcpy(temp, glstack.peek(), sizeof(struct objectx) - sizeof(string));
	temp=shallowcopy(ocast(glstack.peek()));
	xtra = o->instr[++*pc].d;
	ocast(glstack.peek2())->setl(xtra, temp);
	temp->name = getsymbolname(xtra);
}
svmfn(sets){
	object temp,p,p2;
    size_t xtra;
	//temp = object::create();
	//memcpy(temp, glstack.peek(), sizeof(struct objectx) - sizeof(string));
	
	p=ocast(glstack.peek());
	p2=ocast(glstack.peek2());
	
	temp=shallowcopy(p);
	xtra = o->instr[++*pc].d;
	p2->sets( xtra, temp);
	temp->name = getsymbolname(xtra);
}
svmfn(setp){
	object p,p2;
	p=ocast(glstack.peek());
	p2=ocast(glstack.peek2());
	p2->parent = p;
}
svmfn(eval){
	object temp,noway;
    size_t next=o->instr[++*pc].d;
	temp =ocast(glstack.pop());
    noway=temp->eval(next);
	run(noway,temp);
}
svmfn(peval){
	object temp;
    PRIMFN addr=(PRIMFN)(o->instr[++*pc].d);
	temp =ocast( glstack.pop());
	voidanyargs(temp);
	(*addr)(temp);

}
svmfn(evalx){
	object rec,noway,copy;
    size_t message,num;
    message=o->instr[++*pc].d;
    num=o->instr[++*pc].d;
    rec=ocast(glstack.pop());
		noway=rec->eval(message);
        if (noway->instr==0){while(num>0){glstack.pop();num--;};glstack.push(noway);}
        else
        {
			copy=shallowcopy(noway);//DRIZZLE was ,noway became rec
            copy->self=rec;//DRIZZLE was=rec became =copy
			//copy->instr=noway->instr;//DRIZZLE all new line
            
			copy->locals=newtree;

			if(copy->args!=0){//if obj expects args...
				MESSAGE feena;
				while(num>copy->args->numberin){glstack.pop();num--;};//discard spare input args at the start because they're backwards...
                                
				iterate(copy->args,MESSAGE,feena)
				

					if(num>0){
					
						object p;
					//svmprint ("getting an arg");
						p=ocast(glstack.pop());
                     //  svmprint("set to %s=%d\n",p->name,p->value);
						copy->setl(feena,p);//if input arg available, use it
						num--;
					}
					else {
						copy->setl(feena,refobj(void));//else we have run out of input args
					}									//so set it to 0
                 enditerate
				//	svmprint("ARGEJND");
				//if we still have spare input args, discard them...
				//while(num>0){glstack.pop();num--;}

			}
			else {
				//no args expected- discard 'em all
				while(num>0){glstack.pop();num--;}
			}

            run2(copy);
			noway->value=copy->value;noway->parent=copy->parent;//DRIZZLE all new line
         }

}

svmfn(pevalx){
	object temp;
    size_t num;
	PRIMFN addr;
    addr=(PRIMFN)(o->instr[++*pc].d);
    num=o->instr[++*pc].d;
    temp=ocast(glstack.pop());
    //*pc+=num; no message numbers to skip over
	(*addr)(temp);
}
svmfn(evalxs){
	//same as evalx, but instead of popping rec(eiver) off the stack, we use o
	           object noway,copy;
            size_t message,num;
            message=o->instr[++*pc].d;
            num=o->instr[++*pc].d;

                noway=o->eval(message);
                if (noway->instr==0){while(num>0){glstack.pop();num--;};glstack.push(noway);}
                else
                {
                copy=shallowcopy(noway);//DRIZZLE was ,noway became o
                copy->self=o;//DRIZZLE was=o became copy
				//copy->instr=noway->instr;//DRIZZLE all new line
                copy->locals=newtree;
               //

				if(copy->args!=0){//if obj expects args...
				MESSAGE feena;
				while(num>copy->args->numberin){glstack.pop();num--;};//discard spare input args at the start because they're backwards...

				//iterate(copy->args,MESSAGE,feena)
			
				//copy->args->print();
				
				(copy->args)->it=(copy->args)->start;
				while( (copy->args)->it!=(copy->args)->end ){
					(copy->args)->it=(copy->args)->it->next;
					(feena)=(MESSAGE)((copy->args)->it->data.vp);


					if(num>0){
						object p;
						p=ocast(glstack.pop());
						copy->setl(feena,p);//if input arg available, use it
						num--;
					}
					else {
						copy->setl(feena,refobj(void));//else we have run out of input args
					}									//so set it to 0
				enditerate
				//if we still have spare input args, discard them...
			//	while(num>0){glstack.pop();num--;}

			}
			else {
				//no args expected- discard 'em all
				while(num>0){glstack.pop();num--;}
			}

			//


                run2(copy);
				noway->value=copy->value;noway->parent=copy->parent;//DRIZZLE all new line
                }


}

svmfn(pevalxs){
            size_t num;
			PRIMFN addr;
            addr=(PRIMFN)(o->instr[++*pc].d);
            num=o->instr[++*pc].d;
			//*pc+=num; No message numbers to skip over
			(*addr)(o->self);
}

/*svmfn(evalas){
	object noway,temp;
    size_t next=o->instr[++*pc].d;
    latestarg=glstack.pop();
	obj_eval(o, next,noway);runA(noway,o->self,next);
}*/
/*svmfn(pevalas){
    PRIMFN addr=o->instr[++*pc].d;
    latestarg=glstack.pop();
	actualobj=o;
	(*addr)(o->self);
}*/

svmfn(evals){
   object noway;
   size_t next=o->instr[++*pc].d;
   noway=o->eval(next);
   run(noway,o->self);
}
svmfn(pevals){
	PRIMFN addr=(PRIMFN)(o->instr[++*pc].d);
	actualobj=o;
	voidanyargs(o->self);
	(*addr)(o->self);
}
svmfn(neval){
	object noway;
    size_t next;
    object temp= ocast(glstack.pop());
    next=o->instr[++*pc].d;
    noway=temp->eval(next);
	glstack.push(noway);
}
svmfn(nevals){
    object noway;
    size_t next=o->instr[++*pc].d;
    noway=o->eval(next);
	glstack.push(noway);
}
/*svmfn(evala){
	object noway,temp;
    size_t next=o->instr[++*pc].d;
	latestarg=glstack.pop();
	temp = glstack.pop();
    obj_eval(temp, next,noway);runA(noway,temp,next);
}*/
/*svmfn(pevala){
	object temp;
    PRIMFN addr=o->instr[++*pc].d;
	latestarg=glstack.pop();
	temp = glstack.pop();
	(*addr)(temp);
}*/
svmfn(int){
	object temp;
	initobject(temp);
	temp->name = (char*)CSaninteger;
	temp->parent = refobj(integer);
	temp->value.d = o->instr[++*pc].d;
    temp->isnamed = 1;
    glstack.push(temp);
}
svmfn(str){
	object temp,temp2;
	initobject(temp);
	initobject(temp2);
	temp->parent = refobj(string);
	temp->name = (char*)CSastring;
	temp->value.d = o->instr[++*pc].d;
    temp->isnamed = 1;
	//temp2 must be a new int //////or maybe just instruction string evaluates string newfrom: x
	temp2->name = (char*)CSaninteger;
	temp2->parent = refobj(integer);
	temp2->value.d = STRLEN(temp->value.d);
    temp2->isnamed = 1;
	temp->sets(refmsg(length),temp2);
	glstack.push(temp);
}
svmfn(float){
	object temp;
	initobject(temp);
	temp->parent = refobj(float);
	temp->value.f = o->instr[++*pc].f;
	temp->name = (char*)CSafloat;
    temp->isnamed = 1;
    glstack.push(temp);
}
void init_svm_codes(){
	svmcode(eval,1);
//	svmcode(evala,1);
	svmcode(evals,1);
//	svmcode(evalas,1);
	svmcode(evalx,5);
	svmcode(evalxs,5);
	svmcode(peval,4);
//	svmcode(pevala,1);
	svmcode(pevals,4);
	svmcode(sets,1);
	svmcode(pevalx,6);
	svmcode(pevalxs,6);
	svmcode(neval,1);
	svmcode(nevals,1);
	svmcode(setl,1);
	svmcode(ctos,0);
	svmcode(float,2);
	svmcode(int,2);
	svmcode(str,3);
	svmcode(obj,0);
	svmcode(seteval,4);
	svmcode(setp,0);
	svmcode(block,0);
}

