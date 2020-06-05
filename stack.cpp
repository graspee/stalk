class stack{

	

public:
	//public members
	node tos;
	size_t stackcount;

	//public methods
	stack(){
		tos=newnode;
	}
	template< class T > inline void push(T* x){
		node temp;
		temp=newnode;
		temp->data.vp=reinterpret_cast<void*>(x);
		temp->next=tos;
		tos=temp;
			stackcount++;
			#ifdef svm_tracing
				if(glTrace==1){
				{ int g;for(g=0;g<glIndent;svmprint(" ")) {g++;} }
				pen_wht
				svmprint("PUSH ");
				pen_nor
				
				dump();
				}
				
			#endif
	}
	
	//template< class T > inline void push(T& x){
	//	node temp;
	//	temp=node::create();
	//	temp->data.vp=&x;//was &x
	//	temp->next=tos;
	//	tos=temp;
	//		stackcount++;
	//		#ifdef svm_tracing
	//			if(glTrace==1){
	//			{ int g;for(g=0;g<glIndent;svmprint(" ")) {g++;} }
	//			pen_wht
	//			svmprint("PUSH ");
	//			pen_nor
	//			
	//			dump();
	//			}
	//			
	//		#endif
	//}
	inline void* pop(){
		void* temp;
#ifdef svm_error_check
		test(stackcount==0,"attempt to pop from empty stack!");
#endif
		stackcount--;
		temp=tos->data.vp;
		tos=tos->next;
		#ifdef svm_tracing
			if(glTrace==1){
			{ int g;for(g=0;g<glIndent;svmprint(" ")) {g++;} }
			pen_wht
			svmprint("POP ");
			pen_nor
			dump();
			}
			
		#endif
 
		return temp;
	}

	inline void* peek(void){
#ifdef svm_error_check
		test(stackcount==0,"attempt to peek at empty stack!");
#endif
		void* temp;
		temp=tos->data.vp;
		return temp;
		//return tos->data.vp;

	}
	inline void* peek2(void){
#ifdef svm_error_check
		test(stackcount<2,"attempt to peek at one under top of stack when stack has less than 2 items!");
#endif
		return tos->next->data.vp;

	}

	void dump(void){

		object dargo;
		size_t f;
		char* skipula;//why was this treenode???? wtf?
		node temp;
		temp=tos;

			for(f=0;f<stackcount;f++){
			
			dargo=ocast(temp->data.vp);
			skipula=dargo->name;
			if(skipula!=0){
				if(skipula==CSaninteger)svmprint(" [%d]",dargo->value);
				else if(skipula==CSastring)svmprint(" \"%s\"",dargo->value);
							else svmprint(" %s",skipula);

					}else {svmprint(" ?");}

			//svmprint("\n");
			temp=temp->next;
		}
			svmprint("\n");
	}

};

stack glstack;

