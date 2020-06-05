#ifndef svmincluded_gcobject_hpp

#define svmincluded_gcobject_hpp


#define newobject objectbase::create()
	



class objectbase{
	public:
	
	uf* instr;
    object parent;
    tree locals;
	tree statics;
	uf value;
    object self;
    list args;
	bitfield_type isnamed:1;
    char* name;

	static object create(void){object temp=reinterpret_cast<object>(my_calloc(sizeof(objectbase)));return temp;}

	

	inline void setl(MESSAGE b,object c)		{locals->set(b,c);}
	inline void sets(MESSAGE b,object c)		{statics->set(b,c);}
	inline void* getl(MESSAGE b)			{locals->get(b);}
	inline object gets(MESSAGE b)			{return statics->get(b);}
	inline  object findl(MESSAGE b)			{return locals->find(b);}
	inline object  finds(MESSAGE b)			{return statics->find(b);}

inline void msg_dnu(MESSAGE b){
    pen_red
    svmprint("%s does not understand ", name);
    printsymbolname(b);svmprint(" \n");
    pen_nor}


inline object eval(MESSAGE m){
    object into;
	visited=newlist;
    into=eval2(m);
    if(into==objnil){
		into=refobj(void);
		msg_dnu(m);
    }
	return into;
}

object eval2(MESSAGE themessage)
{
    static object tt;
    static char result;
    object temp;

    if(visited->includes(this)){return objnil;}//(object)0
    else{add(visited,this);
#ifdef svm_tracing
	glNumMessageSends++;
#endif
	
	}

    if(this==0)
		return objnil;
    else{
        tt=findl(themessage);
        if(tt!=objnil){return tt;}//return((object)( tt) );
        else{
            tt=finds(themessage);
			if(tt!=objnil){return tt;}//(object)( tt) )
			else{
			
				if(  (object)(this)  !=self)
				{temp=self->eval2(themessage);
				if(temp!=objnil)return(temp);}


				return parent->eval2(themessage);
			}
        }

    }
}



};


typedef void (*PRIMFN)( object );//WTF?


#endif