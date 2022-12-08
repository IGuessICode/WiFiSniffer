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

void push(Node **head_ptr, Node *new_node) {
	new_node->next = *head_ptr;
	*head_ptr = new_node;
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

// UNUSE - void insert_after(Node *prev_node, Node *new_node);

Node* clone_list(Node *head) {
	Node *current = head;
	Node *cpy_list = NULL;
	Node *tail = NULL;

	while (current != NULL) {
		Node *cpy_node = (Node*) malloc(sizeof(Node));
		memcpy(cpy_node, current, sizeof(Node));

		if (cpy_list == NULL) {
			push(&cpy_list, cpy_node);
			tail = cpy_list;
		}
		else {
			push(&(tail->next), cpy_node);
			tail = tail->next;
		}
		current = current->next;
	}

	return cpy_list;
}

void print_list(Node *head) {
	/*
	int key = 0;
	while (head != NULL) {
		print(key, head->data); // REVISE
		key++;
		head = nead->next;
	}
	*/
	while (head != NULL) {
		print(head->data); // REVISE
		head = head->next;
	}
	printf("\n");
}

	//Print node would just be find node and a printing for networks
int print_node(int req_cell, Node *head) {
	int printed = 0;

	while (head != NULL) {
		if (head->data.cell == req_cell) {
			print(head->data);
			printed++;
		}
		head = head->next;
	}

	printf("END OF LIST - That`s all folks\n"); //For debugging

	return printed;
}


/*
void delete_node(Node **head_ptr, int key) { // NOT SURE WE ARE GONNA USE IT TBH
	Node *tmp = *head_ptr, *prev;

	// Node to be deleted is the first pos
	if (tmp != NULL && tmp->data.cell == key) {
		//TODO
	}

	// If not, we find the matching node (if any)
	while (tmp != NULL && tmp->data.cell != key) {
		//TODO
	}

	// If not found nothing is done
	if (tmp = NULL) {
		printf("The node %d was not found.\n", key);
		return;
	}

	//COMMENTED
	 If found, prev connects to next and then, mem
	   of match node is released //END COMMENT
	prev->next = tmp->next;
	free(tmp);
} */

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
