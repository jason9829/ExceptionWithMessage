#include "@@@@Exception.c"
#include "src/Exception.c"
#include "build/temp/_test_Exception.c"
#include "CExceptionConfig.h"
#include "CException.h"
#include "Exception.h"
#include "unity.h"










void setUp(void){}

void tearDown(void){}

void throwError2(int errorCode,char *msg){

  Exception *ex = (Exception*)malloc(sizeof(Exception));

  ex-> errorCode = errorCode;

  ex-> errorMsg = msg;

  Throw(ex);

}





char * names[] = {

  "Ali",

  "David",

  "Ah Beng",

  "Jason"

};





char *getName(int index){

  if(index >= 4 || index < 0)

  {

    throwError(3,"Error: Out of bound of the array. Index given was %d ", index);

  }

  return names[index];

}



int add (int num,...){

  va_list valist;

  int i, sum = 0;



  

 __builtin_va_start(

 valist

 ,

 num

 )

                      ;

  for (i = 0; i < num; i++) {

    sum += 

          __builtin_va_arg(

          valist

          ,

          int

          )

                             ;

 }

  

 __builtin_va_end(

 valist

 )

               ;

  return sum;

}







void printAllNumbers(char *format,...){

  va_list valist;

  int neededSize = 0;

  char *buffer;



  

 __builtin_va_start(

 valist

 ,

 format

 )

                        ;

  neededSize = vsnprintf(buffer, 0, format, valist) + 1;

  buffer = malloc(neededSize);

  vsnprintf(buffer, neededSize, format, valist);

  

 __builtin_va_end(

 valist

 )

               ;



  printf(buffer);

}



void test_printAllNumbers(void){

  printAllNumbers("%f, %d, %x, %s", 1234.56789, 654321, 255, "Heyyyy");

}

void test_add_given_1_2_3_4_5_exptect_15(void){

  int result = add(5, 1, 2, 3, 4, 5);

  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

}



void test_add_given_9_8_7_exptect_24(void){

  int result = add(3, 9, 8, 7);

  UnityAssertEqualNumber((UNITY_INT)((24)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

}



void test_Exception_given_1_expect_David(void){

    Exception * e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception *)0X5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(1);



  } else { } CExceptionFrames[MY_ID].Exception = ((Exception *)0X5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception *)0X5A5A5A5A))

  {

    UnityFail( ((e->errorMsg)), (UNITY_UINT)(96));



  }



}



void test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND(void){

    Exception * e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception *)0X5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(-1);

    UnityFail( (("Expected ERR_OUT_OF_BOUND, but none")), (UNITY_UINT)(107));



  } else { } CExceptionFrames[MY_ID].Exception = ((Exception *)0X5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception *)0X5A5A5A5A))

  {











  }



}



void test_Exception_given_4_expect_ERR_OUT_OF_BOUND(void){

    Exception * e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception *)0X5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(4);

    UnityFail( (("Expected ERR_OUT_OF_BOUND, but none")), (UNITY_UINT)(125));



  } else { } CExceptionFrames[MY_ID].Exception = ((Exception *)0X5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception *)0X5A5A5A5A))

  {











  }



}
