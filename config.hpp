//#pragma warning(disable : 4100)

//Set this to enable the trace facilities.
//Disable tracing at compile time for unnoticably faster execution
#define svm_tracing

//set this to enable basic run time error checking.
//(Stack checks, illegal instructions and so forth)
#define svm_error_check

//set this to turn tracing on right from the start so you can see it do things...
//#define svm_tracefromstart

//set this to enable error checking in such things
//as the string-handling primitives
//#define svm_error_check_runtimes

//colour option- set for colour
#define svm_colour

//colour method- choose only one
//(ignored if svm_borland_gui is set)
#define svm_colour_ansi
//#define svm_colour_win32_console


//set this if you don't have real readline
//commandline will not have editing other than delete and no history
//NT/2000 has some functionality in this regard though.
//ignored if svm_borland_gui is set
//#define svm_no_readline

//set this if you don't want GTK stuff
#define svm_no_gtk


// Standard c would have you use an unsigned int for bitfields
// Both visual c and gcc allow you to have an unsigned char if you want
typedef  unsigned char bitfield_type;


