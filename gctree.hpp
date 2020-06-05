#ifndef svmincluded_tree_hpp

#define svmincluded_tree_hpp

/*struct treenodex {
	size_t key;
	treenodex* left,*right;
	void* data;
};
typedef treenodex* treenode; //was struct treenode*
*/



#define newtree treebase::create()
	
class treebase;
typedef  treebase* tree;



//tree
class treebase{
	public:
	
	size_t key;
	tree left,right;
	object data;

		static tree create(void){tree temp=reinterpret_cast<tree>(my_calloc(sizeof(treebase)));return temp;}



object find(size_t k){
 	if(key==0)return objnil; //empty tree
	else {
		if(key==k)return data;
		else
		if(k>key){if(right==0)return objnil; else return right->find(k);}
		else
		//if(k<t->key){
			if(left==0)return objnil; else return left->find(k);
		//	}
	}
}



//sets key k to data d in tree t. always wins. no retval.
//template < class T > void* set (size_t k,T* d){
//	if(key==0){key=k;data=d;return 0;} //tree was empty
//	else {
//		if(key==k){key=k;data=d;return 0;}//there was a node already with this key
//		else
//			if(k>key){if(right==0){right=tree::create();right->key=k;right->data=d;return 0;}
//			else right->set(k,d);}
//		else
//		//if(k<t->key){
//		if(left==0){left=tree::create();left->key=k;left->data=d;return 0;}
//				else left->set(k,d);
//			//}
//	}
//}
void* set (size_t k,object d){

//object* tp;
#define innertreeset key=k;data=d;return 0; 
#define innertreeset2(a) (a)->key=k;(a)->data=d;return 0;

	if(key==0){innertreeset} //tree was empty
	else {
		if(key==k){innertreeset}//there was a node already with this key
		else
			if(k>key){if(right==0){right=newtree;innertreeset2(right)}
			else right->set(k,d);}
		else
		//if(k<t->key){
		if(left==0){left=newtree;innertreeset2(left)}
				else left->set(k,d);
			//}
	}
}

//get- returns data item with key k from tree t. you must know it is in there! (or else stuff will probably crash)
object get(size_t k){
	if(key==k)return data;
	else
	if(k>key)return right->get(k);
	else
	return left->get(k);
}



};







#endif