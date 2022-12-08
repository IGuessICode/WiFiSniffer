#include "network.h"

#ifndef NODELIB_H
#define NODELIB_H

typedef struct Node {
	network data;
	struct Node *next;
} Node;

Node* create_node(network network);
void push(Node **head_ref, Node *new_node);
void append(Node **head_ref, Node *new_node);
// UNUSE - void insert_after(Node *prev_node, Node *new_node);
Node* clone_list(Node *head); // To invoke it in the diff funct
void print_list(Node *head);
	//Print node would just be find node and a printing for networks
int print_node(int cell, Node *head);
void delete_node(Node **head_ref, int key);
void clear_list(Node **head_ref); // Free memory

#endif //NODELIB_H
