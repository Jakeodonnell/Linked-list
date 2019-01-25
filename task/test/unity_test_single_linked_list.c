#include<setjmp.h>
#include "../unity/unity.h"
#include "../test/test_functions_single_linked_list.h"	
#include "../src/single_linked_list.h"


/* Create a data structure holding your linked list */
struct linkedList list;

void setUp(void);
void tearDown(void);
void resetTest(void);

int main(void) {
    
  UnityBegin("Testing function initLinkedList");
  RUN_TEST(testInitLinkedList, 17);
  resetTest();
  RUN_TEST(testAddLinkedList, 18);
  resetTest();
  RUN_TEST(testRemoveFirst, 19);
  resetTest();
  RUN_TEST(testRemoveLast, 20);
  resetTest();
  RUN_TEST(testAddRemoveLast, 21);
  resetTest();
  RUN_TEST(testAddRemoveFirst, 22);
  resetTest();
  RUN_TEST(testRemoveFirstWhenEmpty, 23);
  resetTest();
  RUN_TEST(testRemoveLastWhenEmpty,24);
  UnityEnd();
  return 0;
}


/*
 * This function will be run automatically when you call RUN_TEST
 */
void setUp(void) {
  if (list.first != NULL) {
    while(removeFirstElement(&list) != INT_MIN) {}
  }
  else {
    initLinkedList(&list);
  }
}

void tearDown(void) {
}

void resetTest(void) {
  tearDown();
  setUp();
}

