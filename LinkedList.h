// Calvin Lee, February 10th

// Header file for singly linked list definitions
// Data set as int, change when necessary
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// struct definition
typedef struct {
  int data;
  void *next;
} Node;

// create head of list
Node *createHead();

// create and push a node to the beginning of the list (O(1))
Node *addNode(Node *head, int data);

// create and append a node to the end of the list (O(n))
Node *appendNode(Node *head, int data);

// remove a node from the end of list
void popNode(Node *head);

// remove a node with a given data value from the list
int removeNode(Node *head, int value);

// insert a node into some position in the list
int insertNode(Node *head, int data, int pos);

// delete the list and free up memory
void deleteList(Node *head);

// print the contents of the list (for debugging purposes)
void printList(Node *head);

#endif