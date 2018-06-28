#ifndef _EXCEPTION_H
#define _EXCEPTION_H

/*typedef struct {        C++ can't compile
  int   errorCode;
  char *errorMsg;
}Exception;
*/

void throwError(int errorCode,char *format,...);

//**********This********  Equal this
typedef struct Exception Exception;
struct Exception{
  int   errorCode;
  char *errorMsg;
};

#endif // _EXCEPTION_H
