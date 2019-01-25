#include<setjmp.h>
#include "../unity/unity.h"
#include "../test/test_functions_double_linked_list.h"	
#include "../src/double_linked_list.h"


/* Create a data structure holding your linked list */
struct linkedList list;

void setUp(void);
void tearDown(void);
void resetTest(void);

int main(void) {
    
  UnityBegin("Testing function initLinkedList");
  RUN_TEST(testInitLinkedList, 17);
  RUN_TEST(testAddElement, 18);
  RUN_TEST(testRemoveFirstElement, 19);
  RUN_TEST(testRemoveLastElement, 20);
  RUN_TEST(testAddRemoveFirst, 21);
  RUN_TEST(testAddRemoveLast, 22);
  RUN_TEST(testRemoveFirstElement,23);
  RUN_TEST(testRemoveLastElement,23);
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

