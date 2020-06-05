#ifndef included_svm_codes_hpp
#define included_svm_codes_hpp

#define svm_eval 1001 //eval x=evaluate message no x in current context and push it
//#define svm_evala 1002 //eval with arg
#define svm_evals 1003 //evals is like selfsend in self
//#define svm_evalas 1004 //like evala but implicit self
#define svm_evalx 1005 //multi-arg eval- 2 things on stack for it
#define svm_evalxs 1006 //as above but send to object itself

#define svm_peval 1007 //eval x=evaluate message no x in current context and push it
//#define svm_pevala 1008 //eval with arg
#define svm_pevals 1009 //evals is like selfsend in self
#define svm_sets 1010
#define svm_pevalx 1011 //multi-arg eval- 2 things on stack for it
#define svm_pevalxs 1012 //as above but send to object itself

#define prim_diff svm_peval - svm_eval

#define svm_neval 1013
#define svm_nevals 1014 //these 2 are the same as eval and evals except they don't evaluate the argument

#define svm_setl 1015 //set x=set message x to top of stack
#define svm_ctos 1016 //clears top of stack
#define svm_float 1017 //float x=creates an obj for float val x and pushes it
#define svm_int 1018 //uint x=creates an obj for int val x and pushes it
#define svm_str 1019 //str x=creates an obj for string val x and pushes it
#define svm_obj 1020 //obj creates new blank obj on stack
#define svm_seteval 1021 //seteval x sets eval to the t_list at address x
#define svm_setp 1022 //no argument- simply sets parent of tos-1 to tos
#define svm_block 1023 //just like object except different


#endif
