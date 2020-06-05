//#pragma warning( error: 4013 )


#include "config.hpp"


void* nil;

class objectbase;
typedef  objectbase* object;
#define ocast(x) (reinterpret_cast<object>(x))

object objnil;

#ifndef svm_no_gtk
	#include "./gtk/gtk.h"
        #include "./gtk/gtkinvisible.h"
#endif




#ifdef svm_borland_gui
	#define svmprint borlandguiprintf
#else
	#define svmprint printf
#endif

#ifdef svm_colour

	//Using colour

	#ifdef svm_borland_gui

		//borland richedit colour routines

	#else

		#ifdef svm_colour_ansi

            #define pen_red svmprint("\033[01;31m");
            #define pen_grn svmprint("\033[01;32m");
            #define pen_yel svmprint("\033[01;33m");
            #define pen_blu svmprint("\033[01;34m");
            #define pen_pnk svmprint("\033[01;35m");
            #define pen_cyn svmprint("\033[01;36m");
            #define pen_wht svmprint("\033[01;37m");
            #define pen_nor svmprint("\033[0m");

			#else

				#ifdef svm_colour_win32_console

					#include <windows.h>
					#include <wincon.h>
					#include <winbase.h>
					//#define STD_OUTPUT_HANDLE -11

					#define pen_red SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0C);
					#define pen_grn SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0A);
					#define pen_yel SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0E);
					#define pen_blu SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x09);
					#define pen_pnk SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0D);
					#define pen_cyn SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0B);
					#define pen_wht SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0F);
					#define pen_nor SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);

				#endif //colour win32 console

			#endif //colour ansi

		#endif //borland gui

	//#endif

#else

	//Not using colour

	#ifdef svm_borland_gui

	//no colour borland richedit

	#else

		#define pen_red
		#define pen_grn
		#define pen_yel
		#define pen_blu
		#define pen_pnk
		#define pen_cyn
		#define pen_wht
		#define pen_nor

	#endif

#endif





extern "C" char string_buf[80];
extern "C" char *string_buf_ptr;
extern "C" int yyparse(void);
extern "C" int yyerror(char*s);
extern "C" int yylex(void);

extern "C" struct yy_buffer_state* yy_scan_string(const char* a);



const char CSaninteger[] = "integer object";
const char CSunknown[] = "???";
const char CStemp[] = "temp_obj";
const char CSastring[] = "string object";
const char CSafloat[] = "float object";
const char CStempblock[]="temp_block";
const char CSatime[]="time object";
const char CSasignal[]="signal object";

typedef unsigned char* string;

//from parser.y
///////////////////////
#define YYERROR_VERBOSE
#define YYDEBUG 1

/////////////////////////
//necessary sys files



#include <ctype.h>
#include <string.h>

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>

extern "C" FILE* yyin;
extern "C" char* yytext;

#define STRSTR(a,b) strstr((char*)(a),(char*)(b))
#define STRLEN(a) strlen((char*)(a))
#define MEMCPY(a,b,c) memcpy((void*)(a),(void*)(b),(size_t)(c))
#define STRCMP(a,b) strcmp((char*)(a),(char*)(b))
#define STRNCPY(a,b,c) strncpy ((char*)(a),(const char*)(b),(c))
#define STRCPY(a,b) strcpy ((char*)(a),(const char*)(b))
#define STRTOD(a,b) strtod((const char*)(a),(char**)(b))
#define STRTOL(a,b,c) strtol((const char*)(a),(char**)(b),(int)(c))
#define STRTOUL(a,b,c) strtoul((const char*)(a),(char**)(b),(int)(c))
typedef size_t MESSAGE;







union uftype{
  size_t d;
  float f;
  void* vp;
  char* c;
//  PRIMFN fn;
};

typedef union uftype uf;


//#include "./gc6.0/include/gc.h"
#include "gc.h"
#include <malloc.h>
#define my_malloc(howmany) GC_MALLOC(howmany)
#define my_calloc(howmany) GC_MALLOC(howmany)


#include "gctree.hpp"

#include "svm_codes.hpp"
#include "gclist.hpp"

list visited;
#ifdef svm_tracing
	char glTrace,glStats,glGCStats;
	unsigned short int glIndent;
	size_t glNumInstr,glNumMessageSends,glMaxDepth;
#endif
	
inline void* nget(list table[],size_t key);
#define getsymbolname(a) (  (char*) (nget(symbol_table,newadjust(a)))  )  //can we get rid of divide?
#define printsymbolname(a) \
    {switch(a%3){\
    case 1: svmprint(getsymbolname(a));svmprint(":");break;\
    case 2: svmprint("$");svmprint(getsymbolname(a));break;\
    case 0: svmprint(getsymbolname(a));break;\
    }}

#define table_size 241 /* best if it's a prime */
list messages[table_size];
list symbol_table[table_size];
list prim_table[table_size];
#define newadjust(a) (a-((a-1)%3)) //gives low of the 3, eg 1-3 is 1,4-6 is 4
#define refmsg(x) lookup(#x)+2
//class objectbase;
//typedef  gc< objectbase > object;
object  object_stalk;

size_t lookup (const  char* name);
#define refobj(x) (object_stalk->gets(lookup(#x)+2))
#include "gcobject.hpp"

#include "svm_codes.cpp"



#define test(a,b) if(a) { pen_red svmprint(b); pen_nor exit(1); }


#define newnew(x) reinterpret_cast<x*>(my_calloc(sizeof(struct x)))

size_t lookup (const char* name);
#include "makestrings.hpp"



void init_primitives(void);


//STUFF FROM RUNTIME TO MAKE HASH WORK
//hash tables


struct namevalpair {
	char* name;
	size_t value;	
};

MESSAGE currentmessage;
#include "hash.cpp"







#include "stack.cpp"

#ifdef svm_no_readline
	#define using_history()
	#define add_history(a)
	 char* readline(const char* prompt){
		static char buffer[1024];
        if(prompt)svmprint(prompt);
		gets((char*)&buffer);
		return (char*)&buffer;
	}
#else
	#include "./readline/readline.h"
	#include "./readline/history.h"
#endif


//#ifndef svm_no_gtk
//	#include<gtk/gtk.h>
//#include<gtkinvisible.h>
//#endif

#include "vm.cpp"


