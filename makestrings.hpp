//extern yyleng;
#define makestring(x,y) x=(char*)(    my_malloc(STRLEN(y)+1)    );STRCPY(x,y)



#define makestring_plus(x,y,z)\
x=(char*)(my_malloc(STRLEN(y)+STRLEN(z)+2));\
    STRCPY(x,y);STRCPY(x+STRLEN(y),z)




#define makestring_strip_last(x,y) x=(char*)(  my_calloc(STRLEN(y)));STRNCPY(x,y,STRLEN(y)-1)  ;
//if y is "abc" then x will be abc
#define makestring_strip_ends(x,y) x=(char*)(  my_calloc(STRLEN(y)-1));STRNCPY(x,y+1,STRLEN(y)-2) ;//x[strlen(y)-1]=0//last may not be needed as cleared before use
//might be able to substitute yyleng for strlen(y)

size_t makestring_set(){
	char* temp;
	size_t counter=0;
	for(temp=yytext;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='-' && *(temp+1)=='>'));temp++)
		counter++;
	temp=(char*)my_malloc(counter+1);
	STRNCPY(temp,yytext,counter);
        return lookup(temp)+2;
}
size_t makestring_set_q(){
	char* temp;
	size_t counter=0;
	for(temp=yytext+1;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='-' && *(temp+1)=='>'));temp++)
		counter++;
	temp=(char*)my_malloc(counter+1);
	STRNCPY(temp,yytext+1,counter);
        return lookup(temp)+2;
}
size_t makestring_set_k(){
	char* temp;
	size_t counter=0;
	for(temp=yytext;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='-' && *(temp+1)=='>'));temp++)
		counter++;
	temp=(char*)my_malloc(counter);
	STRNCPY(temp,yytext,counter-1);
        return lookup(temp);
}
size_t makestring_set_k_q(){
	char* temp;
	size_t counter=0;
	for(temp=yytext+1;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='-' && *(temp+1)=='>'));temp++)
		counter++;
	temp=(char*)my_malloc(counter);
	STRNCPY(temp,yytext+1,counter-2);
        return lookup(temp);
}
size_t makestring_from(){
	char* temp;
	size_t counter=0;
	for(temp=yytext;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='<' && *(temp+1)=='-'));temp++)
		counter++;
	temp=(char*)my_malloc(counter+1);
	STRNCPY(temp,yytext,counter);
        return lookup(temp)+2;
}
size_t makestring_from_q(){
	char* temp;
	size_t counter=0;
	for(temp=yytext+1;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='<' && *(temp+1)=='-'));temp++)
		counter++;
	temp=(char*)my_malloc(counter+1);
	STRNCPY(temp,yytext+1,counter);
        return lookup(temp)+2;
}
size_t makestring_from_k(){
	char* temp;
	size_t counter=0;
	for(temp=yytext;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='<' && *(temp+1)=='-'));temp++)
		counter++;
	temp=(char*)my_malloc(counter);
	STRNCPY(temp,yytext,counter-1);
        return lookup(temp);
}
size_t makestring_from_k_q(){
	char* temp;
	size_t counter=0;
	for(temp=yytext+1;*temp!='\n' && *temp!='\t' && *temp!=' ' && (!(*temp=='<' && *(temp+1)=='-'));temp++)
		counter++;
	temp=(char*)my_malloc(counter);
	STRNCPY(temp,yytext+1,counter-2);
        return lookup(temp);
}




