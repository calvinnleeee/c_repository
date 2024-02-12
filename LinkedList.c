// Calvin Lee, February 10th

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/*
*   createHead: creates the head of the linked list
*   return:     a pointer to the head of the list
*/
Node *createHead() {
  Node *head = malloc(sizeof(Node));
  head->next = NULL;
  return head;
}

/*
*   addNode: create and push a node to the beginning of the list
*   param *head:  pointer to head of the list to push to
*   param data:   data to store in the new node
*   return:       a pointer to the new node
*   time complexity: O(1)
*/
Node *addNode(Node *head, int data) {
  Node *new;
  // if there is no list, create a new node with the data
  if (head == NULL) {
    new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    head->next = new;
  }
  // if head is not null
  else {
    new = malloc(sizeof(Node));
    new->data = data;
    new->next = head->next;
    head->next = new;
  }
  return new;
}

/*
*   appendNode: create and append a node to the end of the list
*   param *head:  pointer to the head of the list to append to
*   param data:   data to store in the new node
*   return:       a pointer to the new node
*   time complexity: O(n)
*/
Node *appendNode(Node *head, int data) {
  Node *last = head;
  // move to the last element in the list
  while (last->next != NULL) last = last->next;

  Node *new = malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;
  last->next = new;

  return new;
}

/*
*   popNode: pop a node out from the end of the list, removes it
*   param *head:  pointer to the head of the list to pop
*   time complexity: O(n)
*/
void popNode(Node *head) {
  // only execute if list contains at least one item
  if (head->next != NULL) {
    // need one iterator for current, one to keep track of previous
    // previous turns to the new end of list and needs to point to null after last is removed
    Node *last = head;
    Node *prev = head;
    while (last->next != NULL) {
      prev = last;
      last = last->next;
    }
    prev->next = NULL;
    free(last);
    last = NULL;
  }
}

/*
*   removeNode: remove the first node from the given list with a specified value
*   param *head:  pointer to the head of the list to remove from
*   param value:  value to search for
*   return:       integer: 0 for fail, 1 for success
*   time complexity: O(n) (for worst case with value at end of list or not existing)
*/
int removeNode(Node *head, int value) {
  // check if list exists. fail if it doesn't exist
  if (head->next == NULL) return 0;
  Node *current = head->next;
  Node *prev = head;
  while (current != NULL) {
    if (current->data == value) {
      // if current node is the last item:
      if (current->next == NULL) {
        prev->next = NULL;
        free(current);
        current = NULL;
      }
      // if current node is not the last item
      else {
        prev->next = current->next;
        free(current);
        current = NULL;
      }
      return 1;
    }
    prev = current;
    current = current->next;
  }
  // return 0 for fail if there was no item with specified value
  return 0;
}

/*
*   insertNode: create and insert a node into some position in the list
*   param *head:  pointer to the head of the list to insert into
*   param data:   data value to give to the new node
*   param pos:    position to insert into
*   return:       integer, 1 if successfully inserted into list, 0 if fail
*/
int insertNode(Node *head, int data, int pos) {
  Node *current = head->next;
  Node *prev = head;
  while (current != NULL && pos != 0) {
    pos--;
    prev = current;
    current = current->next;
  }
  // position exceeds size of the list, failed to find position to insert
  if (pos > 0) return 0;

  Node *new = malloc(sizeof(Node));
  new->data = data;
  new->next = current;
  prev->next = new;
  return 1;
}

/*
*   deleteList: deletes the list and frees up memory
*   param *head:  pointer to the head of the list to delete
*/
void deleteList(Node *head) {
  Node *current = head;
  Node *tmp;
  while(current != NULL) {
    tmp = current->next;
    free(current);
    current = tmp;
  }
}

/*  (for debugging purposes)
*   printList: print the entire list starting from the head's next node
*   param *head:  pointer to the head of the list to print
*/
void printList(Node *head) {
  // if head is pointing to nothing, let user know
  if (head->next == NULL) {
    printf("No list exists. Head->next is null.\n");
  }
  // if head does point to something, print the list (index optional)
  else {
    Node *current = head->next;
    int counter = 0;
    while (current != NULL) {
      // printf("(Index %d) ", counter++);
      printf("%d -> ", current->data);
      current = current->next;
      counter++;
    }
    printf("\nNumber of elements: %d\n", counter);
    printf("\n");
  }
}