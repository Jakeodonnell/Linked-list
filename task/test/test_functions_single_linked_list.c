#include "../unity/unity.h"
#include "test_functions_single_linked_list.h"
#include "../src/single_linked_list.h"
#include<limits.h>


extern struct linkedList list;

void testInitLinkedList(void) {
  TEST_ASSERT_NULL(list.first);
}

void testAddLinkedList(void) {
	TEST_ASSERT_EQUAL_INT(10, addElement(&list, 10));
	TEST_ASSERT_EQUAL_INT(1, addElement(&list, 1));
	TEST_ASSERT_EQUAL_INT(100, addElement(&list, 100));
	}

void testRemoveFirst(void) {
	TEST_ASSERT_EQUAL_INT(10, addElement(&list, 10));
	TEST_ASSERT_EQUAL_INT(1, addElement(&list, 1));
	TEST_ASSERT_EQUAL_INT(100, addElement(&list, 100));
	TEST_ASSERT_EQUAL_INT(1, removeFirstElement(&list));
}

void testRemoveLast(void) {
	TEST_ASSERT_EQUAL_INT(10, addElement(&list, 10));
	TEST_ASSERT_EQUAL_INT(1, addElement(&list, 1));
	TEST_ASSERT_EQUAL_INT(10, removeLastElement(&list));
}

void testAddRemoveLast(void) {
	for(int i = 0; i < 10; i++) {
		TEST_ASSERT_EQUAL_INT(i, addElement(&list, i));
	}
	for(int i = 9; i > 0; i--) {
		TEST_ASSERT_EQUAL_INT(i, removeLastElement(&list));
	}
}

void testAddRemoveFirst(void) {
	for(int i = 0; i < 10; i++) {
		TEST_ASSERT_EQUAL_INT(i, addElement(&list, i));
	}
	for(int i = 0; i < 9; i++) {
		TEST_ASSERT_EQUAL_INT(i, removeFirstElement(&list));
	}
}

void testRemoveFirstWhenEmpty(void) {
	TEST_ASSERT_EQUAL_INT(INT_MIN, removeFirstElement(&list));
	}

void testRemoveLastWhenEmpty(void) {
	TEST_ASSERT_EQUAL_INT(INT_MIN, removeLastElement(&list));
	}
  
