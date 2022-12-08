#include "network.h"

#ifndef NODELIB_H
#define NODELIB_H

typedef struct Node {
	network data;
	struct Node *next;
} Node;

Node* create_node(network network);
void append(Node **head_ref, Node *new_node);
void print_list(Node *head);
int print_node(int cell, Node *head);
void clear_list(Node **head_ref); // Free memory

#endif //NODELIB_H
