#include<stdlib.h>
#include<limits.h>
#include"double_linked_list.h"
#include<stdio.h>


int addElement(struct linkedList* list, int value){
	struct linkedListElement* new_node = malloc(sizeof(new_node));
	struct linkedListElement* test = list->first;
	new_node->next = NULL; 
	new_node->previous = NULL;
	new_node->data = value;
	
	if(list->first == NULL){
		new_node->next = list->last;
		new_node->previous = list->first;
		list->first = new_node;
		list->last = new_node;
		return value;
	}
	else if(list->first->data >= new_node->data) {
		new_node->next = list->first;
		list->first = new_node;
		new_node->next->previous = new_node;
		return value;
	}
	 
	else {
	 struct linkedListElement* current_node = list->first;
	while(current_node->next!=NULL && current_node->next->data < new_node->data){
		 current_node = current_node->next;
	 }
	new_node->next = current_node->next;
	if(current_node->next!=NULL){
		  new_node->next->previous = new_node;
	  }
	current_node->next = new_node;
	new_node->previous = current_node;
	if(new_node->next == NULL){
	  list->last = new_node;
	}
	return value;
	}
  return INT_MIN;
} 


void initLinkedList(struct linkedList* list) {
  list->first = NULL;
  list->last = NULL;
}


int removeFirstElement(struct linkedList* list){
	struct linkedListElement* node;
	if(list->first == NULL) {
		return INT_MIN;
		} else {
		node = list->first;
		int val = node->data;
		list->first = node->next;
		if(node->next == NULL){
			list->last = node->next;
		}
		free(node);
		return val;
	}
} 


int removeLastElement(struct linkedList* list) {
 struct linkedListElement* node;
node = list->last;
int val =  node->data;
 if(list->last == NULL) {
	return INT_MIN;
	} else { 
		if(list->last->previous == NULL){
			list->first = NULL;
			free(node);
			return val;
		}
	node->previous->next = NULL;
	list->last = node->previous;
	free(node);
	return val;
 }
}


int print(struct linkedList* list) {
	struct linkedListElement* current_node = list->first;
	int i = 0;
	if (current_node == NULL){
		return INT_MIN;
	}
	printf("\n[FIRST: %i|LAST: %i]\n", list->first->data, list->last->data);
		printf("[DATA: %i|INDEX: %i]\n", current_node->data, i);
	while(current_node->next!= NULL){
		current_node = current_node->next;
		i++;
		printf("[DATA: %i|INDEX: %i|PREV-VAL: %i]\n", current_node->data, i, current_node
		->previous->data);
	}
}