#include "svm_codes.hpp"

#define num_codes 23

struct {
     char name[8];
	unsigned char smart_code;
	void (*fn)(object o,size_t* p);
} svm_codes[num_codes];


void uppercaseize(char address[],char* s){
	char* to,*from;
	from=s;to=(char*)address;
	while(*from){*to++=(*from++)-32;}
	*to=0;
}

#define svmfn(a)\
	void doitfor##a(object o,size_t* pc)

#define svmcode(a,b)\
	uppercaseize(svm_codes[svm_##a - 1001].name,#a);\
	svm_codes[svm_##a - 1001].smart_code=b;\
	svm_codes[svm_##a - 1001].fn=doitfor##a;


