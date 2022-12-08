#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "network.h"
#include "nodelib.h"
#include "collect.h"
#include "display.h"

Node* create_node(network new_network) {
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = new_network;
	node->next = NULL;

	return node;
}

void append(Node **head_ptr, Node *new_node) {
	Node *last = *head_ptr;

	if (*head_ptr == NULL) {
		*head_ptr = new_node;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new_node;
}

void print_list(Node *head) {
	while (head != NULL) {
		print(head->data); // Code in display.c
		head = head->next;
	}
	printf("\n");
}

int print_node(int req_cell, Node *head) {
	int printed = 0;

	while (head != NULL) {
		if (head->data.cell == req_cell) {
			print(head->data);
			printed++;
		}
		head = head->next;
	}

	// printf("END OF LIST - That's all folks\n"); //For debugging

	return printed;
}

void clear_list(Node **head_ptr) {
	Node *current = *head_ptr;
	Node *next;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*head_ptr = NULL;
}
