#define nhash(x) (x%table_size)

struct nhashval {
	size_t value;
	void* data;
};

template <class TT> inline void nset(list table[],size_t key,TT* data){
	nhashval* n;
	size_t k=nhash(key);
	
	//if no list for this hash val- make one
	if(table[k]==0){
		table[k]=newlist;
	}

	//see if key already has a value- if so change it
	
	
	iterate(table[k],nhashval*,n)
	
	
		if (n->value==key){
			n->data=reinterpret_cast<void*>(data);return;
		}

	enditerate
	
	
	
	//else add a new key val pair
	n=(nhashval*)newnew(nhashval);
	((nhashval*)(n))->value=key;
	((nhashval*)(n))->data=reinterpret_cast<void*>(data);
	add(table[k],n);
}

inline void* nget(list table[],size_t key){
	nhashval* d;
	size_t k=nhash(key);
	if(table[k]==0)return 0;
	
	
	
	iterate(table[k],nhashval*,d) 
	
	
		if (d->value==key){
			return d->data;
		}
	
	enditerate


	return 0;
}


//#define tsize table_size*sizeof(unsigned int)

//#define new_hash_table() my_calloc(tsize)

/* SysV elf hashing function */

unsigned long hash(const  char* name){
    unsigned long h=0,g;

    while(*name){
	h=(h<<4)+ *name++;
	if(g=h&0xF0000000)
	    h ^=g>>24;
	h&=~g;
    }
    return h % table_size;
}

size_t lookup
(const  char* name)
{ 
    size_t f,h;
    namevalpair*n;//should be namevalpair*, but iterate...
    h=hash(name);

    if(messages[h]==0){ //nothing in the list for this hash number
	n=(namevalpair*)newnew(namevalpair);
	messages[h]=newlist;
        add(messages[h],n);
	makestring(((namevalpair*)(n))->name,name);
	((namevalpair*)(n))->value=currentmessage;
	nset(symbol_table,currentmessage,((namevalpair*)(n))->name);
	currentmessage+=3;
        return currentmessage-3;
}

    else { //go through the list for this hash number

	iterate(messages[h],namevalpair*,n)	
		
		
	    if(STRCMP(((namevalpair*)(n))->name,name)==0) //ok we found it, return it
		return ((namevalpair*)(n))->value;
	
	enditerate
    }
//although there are entries for this hash number, our string is not in there, so add it
	n=(namevalpair*)newnew(namevalpair);
        add(messages[h],n);
	makestring(((namevalpair*)(n))->name,name);
	((namevalpair*)(n))->value=currentmessage;
	nset(symbol_table,currentmessage,((namevalpair*)(n))->name);
        currentmessage+=3;
        return currentmessage-3;
}
