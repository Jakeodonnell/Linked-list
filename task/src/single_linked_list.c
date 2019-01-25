#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include"single_linked_list.h"


int addElement(struct linkedList* list, int value){
	struct linkedListElement* new_node = malloc(sizeof(new_node));
	new_node->next = NULL;
	new_node->data = value;
	if(list->first == NULL || list->first->data >= new_node->data){
		new_node->next = list->first;
		list->first = new_node;
		return value;
		} else {
		struct linkedListElement* current_node = list->first;
		while(current_node->next!=NULL && current_node->next->data < new_node->data){
			current_node = current_node->next;
		}
		new_node->next = current_node->next;
		current_node->next = new_node;
		return value;
	}
	return INT_MIN;
}

void initLinkedList(struct linkedList* list) {
	list->first = NULL;
}

int removeFirstElement(struct linkedList* list){
	struct linkedListElement* node;
	if(list->first == NULL) {
		return INT_MIN;
		} else {
		node = list->first;
		list->first = node->next;
		int val = node->data;
		free(node);
		return val;
	}
}


int removeLastElement(struct linkedList* list){
	struct linkedListElement *last, *prev;
	prev = list->first;
	last = list->first;
	if(list->first == NULL){
		return INT_MIN;
	} else {
		while(last->next != NULL){
			prev = last;
			last = last->next;
		}
		if(last == list->first){
			list->first = NULL;
		}
		else{
			prev->next = NULL;
		}
		int val = last->data;
		free(last);
		return val;
	}
}

int print(struct linkedList* list) {
	struct linkedListElement* current_node = list->first;
	int i = 0;
	if (current_node == NULL){
		return INT_MIN;
	}
	printf("[DATA%i|INDEX%i]\n", current_node->data, i);
	while(current_node->next != NULL){
		current_node = current_node->next;
		i++;
		printf("[DATA%i|INDEX%i]\n", current_node->data, i);
	}
}