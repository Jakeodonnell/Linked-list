#include "../unity/unity.h"
#include "test_functions_double_linked_list.h"
#include "../src/double_linked_list.h"
#include<limits.h>
extern struct linkedList list;

void testInitLinkedList(void) {
TEST_ASSERT_NULL(list.first);
TEST_ASSERT_NULL(list.last);
}
 
void testAddElement(void) {
	TEST_ASSERT_EQUAL_INT(4, addElement(&list, 4));
	TEST_ASSERT_EQUAL_INT(1, addElement(&list, 1));
	TEST_ASSERT_EQUAL_INT(2, addElement(&list, 2));
	TEST_ASSERT_EQUAL_INT(7, addElement(&list, 7));
	TEST_ASSERT_EQUAL_INT(100, addElement(&list, 100));
	TEST_ASSERT_EQUAL_INT(30, addElement(&list, 30));
 }

void testRemoveFirstElement(void){
	TEST_ASSERT_EQUAL_INT(7, addElement(&list, 7));
	TEST_ASSERT_EQUAL_INT(100, addElement(&list, 100));
	TEST_ASSERT_EQUAL_INT(30, addElement(&list, 30));
	TEST_ASSERT_EQUAL_INT(7, removeFirstElement(&list));

 }

void testRemoveLastElement(void){
	TEST_ASSERT_EQUAL_INT(7, addElement(&list, 7));
	TEST_ASSERT_EQUAL_INT(100, addElement(&list, 100));
	TEST_ASSERT_EQUAL_INT(30, addElement(&list, 30));
	TEST_ASSERT_EQUAL_INT(100, removeLastElement(&list));
 }
void testAddRemoveFirst(void) {
	 for(int i = 1; i < 10; i++){
		 TEST_ASSERT_EQUAL_INT(i, addElement(&list, i));
	 }
	 for(int i = 1; i < 7; i++){
		TEST_ASSERT_EQUAL_INT(i, removeFirstElement(&list));
	 }
	}

void testAddRemoveLast(void) {
	 for(int i = 1; i < 10; i++){
		 TEST_ASSERT_EQUAL_INT(i, addElement(&list, i));
	 }
	 for(int i = 9; i > 0; i--){
		TEST_ASSERT_EQUAL_INT(i, removeLastElement(&list));
	 }
}
void testRemoveFirstWhenEmpty(void) {
	TEST_ASSERT_EQUAL_INT(INT_MIN, removeFirstElement(&list));
	}

void testRemoveLastWhenEmpty(void) {
	TEST_ASSERT_EQUAL_INT(INT_MIN, removeLastElement(&list));
	}

