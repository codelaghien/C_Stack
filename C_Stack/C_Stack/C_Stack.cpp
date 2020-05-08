// C_Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

typedef struct stack {
	linked_list* list; 
} stack;

stack* create_stack();
void push(stack* my_stack, node* new_node);
node* pop(stack* my_stack);
void print_stack(stack* my_stack);
bool is_empty(stack* my_stack);
int stack_size(stack* my_stack);
void destroy(stack* my_stack);

int main()
{
	printf("Stack \n");

	sinh_vien* A = create_sinh_vien("Huy", 30);
	sinh_vien* B = create_sinh_vien("Huy 2", 10);
	sinh_vien* C = create_sinh_vien("Huy 3", 40);

	stack* my_stack = create_stack();
	push(my_stack, create_node(A));
	push(my_stack, create_node(B));
	push(my_stack, create_node(C));
	push(my_stack, create_node(create_sinh_vien("Huy 4", 40)));
	print_stack(my_stack); 

	node* a_node = pop(my_stack);
	print_stack(my_stack);
	if (a_node) { 
		printf("pop lan 1: name = %s, age = %d \n", a_node->data->name, a_node->data->age);
	}
	a_node = pop(my_stack);
	print_stack(my_stack);
	if (a_node) {
		printf("pop lan 2: name = %s, age = %d \n", a_node->data->name, a_node->data->age);
	}

	destroy(my_stack);

	char c = getchar();
	return 0;
}

stack* create_stack() {
	stack* new_stack = (stack*)calloc(1, sizeof(stack));
	new_stack->list = create_list(); 

	return new_stack;
}

void destroy(stack* my_stack) {
	destroy(my_stack->list);
	free(my_stack);
}
void print_stack(stack* my_stack) {
	print_list(my_stack->list);
}

void push(stack* my_stack, node* new_node) {
	insert_before(my_stack->list, new_node, 0);
}

node* pop(stack* my_stack) {
	node* a_node = my_stack->list->head;
	my_stack->list->head = my_stack->list->head->next;
	my_stack->list->size--;
	return a_node;
}

int stack_size(stack* my_stack) {
	return my_stack->list->size;
}
bool is_empty(stack* my_stack) {
	return (stack_size(my_stack) == 0);
}


