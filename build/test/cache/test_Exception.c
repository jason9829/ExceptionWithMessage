#include "build/temp/_test_Exception.c"
#include "CExceptionConfig.h"
#include "CException.h"
#include "Exception.h"
#include "unity.h"






void setUp(void){}

void tearDown(void){}





char * names[] = {

  "Ali",

  "David",

  "Ah Beng",

  "Jason"

};





char *getName(int index)

{

  if(index >= 4 || index < 0)

  {

    Throw("ERROR: Out of bond of the array");



  }

  return names[index];

}





void test_Exception_given_1_expect_David(void)

{

    char * e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((char *)0X5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(1);



  } else { } CExceptionFrames[MY_ID].Exception = ((char *)0X5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((char *)0X5A5A5A5A))

  {

    UnityFail( (("Expected no ERR_OUT_OF_BOUND")), (UNITY_UINT)(39));



  }



}



void test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND(void)

{

    char * e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((char *)0X5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(-1);

    UnityFail( (("Expected ERR_OUT_OF_BOUND, but none")), (UNITY_UINT)(51));



  } else { } CExceptionFrames[MY_ID].Exception = ((char *)0X5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((char *)0X5A5A5A5A))

  {

    printf("Under test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND\n");

    printf("error code: %s",e);

  }



}



void test_Exception_given_4_expect_ERR_OUT_OF_BOUND(void)

{

    char * e;

    char *name;

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((char *)0X5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    name = getName(4);

    UnityFail( (("Expected ERR_OUT_OF_BOUND, but none")), (UNITY_UINT)(67));



  } else { } CExceptionFrames[MY_ID].Exception = ((char *)0X5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((char *)0X5A5A5A5A))

  {



  }



}
