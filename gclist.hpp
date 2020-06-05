#ifndef svmincluded_list_hpp

#define svmincluded_list_hpp
	
#define addst(a,b) (a)->additem((size_t)(b))
#define add(a,b) (a)->additem(reinterpret_cast<void*>(b))
#define t_add(a,b) (a)->additem(reinterpret_cast<void*>(b))
#define t_addst(a,b) (a)->additem((size_t)(b))
#define addf(a,b)
#define t_addf(a,b)
#define addlist(a,b) (a)->additemlist(b)
#define t_addlist(a,b) (a)->t_additemlist(b)


#define iterate(l,t,d)\
	(l)->it=(l)->start;\
while( (l)->it!=(l)->end ){\
	(l)->it=(l)->it->next;\
	(d)=(t)((l)->it->data.vp);

#define enditerate }

	


		
class nodebase;
class listbase;
class t_listbase;

typedef  nodebase* node;
typedef  listbase* list;
typedef t_listbase* t_list;

#define newnode nodebase::create()
#define newlist listbase::create()
#define newtlist t_listbase::create()

//node
class nodebase{
	public:
	
	node next;
	
	union {
		void* vp;
		size_t st;
	} data;

	static node create(void){node temp=reinterpret_cast<node>(my_calloc(sizeof(nodebase)));return temp;}
};
//list
class listbase{
public:
	node start;
	node end;
	node it;
	size_t numberin;
	
	static list create(void){list temp=reinterpret_cast<list>(my_calloc(sizeof(listbase)));
		temp->start=temp->end=newnode;
		return temp;}


	inline void additem(void* i){
		end->next=newnode;
		end=end->next;
		end->data.vp=i;
		numberin++;
        }
	inline void additem(size_t i){
		end->next=newnode;
		end=end->next;
		end->data.st=i;
		numberin++;
        }
template <class TT> inline void additem(TT* i){
		end->next=newnode;
		end=end->next;
		end->data.vp=reinterpret_cast<void*>(i);
		numberin++;
        }
/*	template<class TT>inline void additem(TT& i){
		end->next=node::create();
		end=end->next;
		end->data=reinterpret_cast<void*>(&i);
		numberin++;
        }*/

    /*template<class TT>inline void additem(TT* i){
		end->next=node::create();
		end=end->next;
		end->data=reinterpret_cast<void*>(i);
		numberin++;
	}*/

	inline void additemlist(list b){
		end->next=b->start->next;
		end=b->end;
		numberin+=b->numberin;
	}
	inline void addlist_rev(list b){
		if(numberin==0){
			start=b->start;
			end=b->end;
			numberin=b->numberin;
		}
		else {
			node oldastartnext;
			oldastartnext=start->next;
			start=b->start;
			b->end->next=oldastartnext;
			numberin+=b->numberin;
		}

	}
	template<class TT>inline bool includes(TT* x){
		node temp;
		temp=start;
		while (temp!=end){
			temp=temp->next;
			if(reinterpret_cast<TT*>(temp->data.vp)==x){return true;};
		}
		return false;
        }
    /*template<class TT>inline bool includes(TT x){
		node temp;
		temp=start;
		while (temp!=end){
			temp=temp->next;
			if((TT)(temp->data)==x){return true;};
		}
		return false;
	}*/
	/*inline void iteratebegin(void){
		it=start;
	}
	inline void* iterate(void){
		if(it==end){return 0;}
		else{it=it->next;return it->data.vp;}
	}*/
	inline void print(void){
		node temp;
		temp=start;
		while (temp!=end){
			temp=temp->next;
			if(temp->data.st==0){
				printf("zero ");
			} 
			else {
				printf("%d ", temp->data.st);
			}
		}
	}
};
//t_list
class t_listbase : public listbase{
public:
  //  node start,end,it;  
  //  size_t numberin;
    list args;
	t_list taintlist;							//sublist
    bitfield_type isanobjectcore:1;
	bitfield_type taintflag:1;		      //set if contains assignment operator ->
    bitfield_type extractos:1;		      //set if evals or nevals used
    bitfield_type wordset:1;                  //set if wordset used. Not copied between lists
    bitfield_type taintflag2:1;				//set if statement contains the assignment operator <-
    
	static t_list create(void){t_list temp=reinterpret_cast<t_list>(my_calloc(sizeof(t_listbase)));
		temp->start=temp->end=newnode;
		return temp;}
	
	inline void taint(void){
        taintflag=1;
    }
    inline void taint2(void){
        taintflag2=1;
    }
       /* template<class TT>inline void additem(TT i){
		end->next=node::create();
		end=end->next;
		end->data=(void*)i;
		numberin++;
	}*/
	inline void t_additemlist(t_list b){
            if(b->args!=0 && b->isanobjectcore==0){
			if(args==0){
				args=newlist;
			} 
			args->addlist_rev(b->args);
		}	
	
		if( b->start!=b->end){					
			end->next=b->start->next;			
			end=b->end;	
			numberin+=b->numberin;				
		}						
		if(extractos==0){
			extractos=b->extractos; 
		}
		if(taintflag==0){
			taintflag=b->taintflag;
		}
		if(taintflag2==0){
			taintflag2=b->taintflag2;
		}
		if(b->taintlist!=0){					
			if(taintlist==0){
				taintlist=newtlist;
			} 
			else  {
				add(taintlist,svm_ctos);
			}
			t_addlist(taintlist,b->taintlist);
		}

        }
    

};
//#define list_from_tlist(a,b) initlist(a);a->start=b->start;a->end=b->end





#endif