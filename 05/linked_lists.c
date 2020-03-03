#include <stdio.h>
#include <stdlib.h>

typedef struct l_list{
	int data;
	struct l_list *next;
} node;

void insert_tail(node **head, int data){
	// because this function needs to be able to change the head of the list,
	// it is given the address of the head pointer.
	node *new_element = (node *)malloc(sizeof(node));
	new_element->data = data;
	new_element->next = NULL;
	
	if(*head == NULL){// this is for first insertion
		*head = new_element; return;
	}
	
	// this loop runs until current is pointing to the last element
	node *current = *head;
	while(current->next != NULL){
		current = current->next;
	}
	
	current->next = new_element;
}

void print_list(node *head){
	node *current = head;
	printf("List: { ");
	while(current != NULL){
		printf("%d ", current->data);
		current = current->next;
	}
	printf("}\n");
}

int main(){
	// (this program compiles and runs)
	node *head = NULL;
	insert_tail(&head, 1);
	insert_tail(&head, 2);
	insert_tail(&head, 3);
	print_list(head);
}