#include "unity.h"
#include "Exception.h"
#include "Exception.c"
#include "CException.h"
#include "CExceptionConfig.h"
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>

void setUp(void){}
void tearDown(void){}



// Use combined version
/*void  throwError(int errorCode,char *msg){
  Exception *ex = (Exception*)malloc(sizeof(Exception));
  ex-> errorCode = errorCode;
  ex-> errorMsg = msg;
  Throw(ex);
}
*/
void  throwError2(int errorCode,char *msg){         // can throw user input (index) as message
  Exception *ex = (Exception*)malloc(sizeof(Exception));
  ex-> errorCode = errorCode;
  ex-> errorMsg = msg;
  Throw(ex);
}

// names is array of 4 of pointer to char
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
  va_list valist;                 //valist is a pointer / must at top
  int i, sum = 0;

  va_start(valist, num);          //valist point at num which is first parameter
  for (i = 0; i < num; i++) {     // access all the arguments assigned to valist
    sum += va_arg(valist, int);
 }
  va_end(valist);
  return sum;
}



void printAllNumbers(char *format,...){
  va_list valist;
  int neededSize = 0;
  char *buffer;          // store data

  va_start(valist,format);
  neededSize = vsnprintf(buffer, 0, format, valist) + 1; // since 0 it will return bytes required due to ISO99_source
  buffer = malloc(neededSize);
  vsnprintf(buffer, neededSize, format, valist);
  va_end(valist);

  printf(buffer);
}

void test_printAllNumbers(void){
  printAllNumbers("%f, %d, %x, %s", 1234.56789, 654321, 255, "Heyyyy");
}
void test_add_given_1_2_3_4_5_exptect_15(void){
  int result = add(5, 1, 2, 3, 4, 5);   // first digit is no of elements
  TEST_ASSERT_EQUAL(15, result);
}

void test_add_given_9_8_7_exptect_24(void){
  int result = add(3, 9, 8, 7);   // first digit is no of elements
  TEST_ASSERT_EQUAL(24, result);
}

void test_Exception_given_1_expect_David(void){
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(1);
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    TEST_FAIL_MESSAGE(e->errorMsg); // if thrown but unexptected
    //printf("error code: %s",e->errorMsg);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND(void){
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(-1);
    TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND, but none");   // if not thrown and catch
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {

    //printf("Under test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND\n");
    //printf("%s\n",e->errorMsg);
  //  printf("error code: %d",e->errorCode);
  //  free(e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_4_expect_ERR_OUT_OF_BOUND(void){
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(4);
    TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND, but none");
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {

  //  printf("%s\n",e->errorMsg);
  //  printf("error code: %d",e->errorCode);
  //  free(e);
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}
