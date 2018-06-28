#include "unity.h"
#include "Exception.h"
#include "CException.h"
#include "CExceptionConfig.h"
#include <stdio.h>

void setUp(void){}
void tearDown(void){}

// names is array of 4 of pointer to char
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
  //Throw(ERR_OUT_OF_BOUND);
  }
  return names[index];
}


void test_Exception_given_1_expect_David(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(1);
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    TEST_FAIL_MESSAGE("Expected no ERR_OUT_OF_BOUND"); // if thrown but unexptected
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(-1);
    TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND, but none");   // if not thrown and catch
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    printf("Under test_Exception_given_minus_1_expect_ERR_OUT_OF_BOUND\n");
    printf("error code: %s",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}

void test_Exception_given_4_expect_ERR_OUT_OF_BOUND(void)
{
    CEXCEPTION_T e;
    char *name;
    Try{
    name = getName(4);
    TEST_FAIL_MESSAGE("Expected ERR_OUT_OF_BOUND, but none");
    //printf("Name is %s\n",name);
  } Catch(e)            //catch and put in e
  {
    //printf("error code: %d",e);
  }
    //TEST_ASSERT_EQUAL_STRING("David",name);
}
