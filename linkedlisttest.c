#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

void printMenu(Node *head) {
  printf("\nSelect an option\n");
  printf("\t1. Add a node to the beginning of the list\n");
  printf("\t2. Append a new node to the end of the list\n");
  printf("\t3. Insert a node to some position in the list\n");
  printf("\t4. Pop a node from the end of the list\n");
  printf("\t5. Remove the first node in the list with some value\n");
  printf("\t6. Swap two nodes\n");
  printf("\t7. Print the list\n");
  printf("\t8. Quit\n");
  int option = -1;
  int success = -1;
  int val;
  int pos;
  int pos2;
  int num_received = scanf("%d", &option);
  if (num_received == 1 && option > 0 && option <= 8) {
    switch(option) {
      case 1:
        printf("Data value: ");
        scanf("%d", &val);
        addNode(head, val);
        printf("\n");
        break;
      case 2:
        printf("Data value: ");
        scanf("%d", &val);
        appendNode(head, val);
        printf("\n");
        break;
      case 3:
        printf("Data value: ");
        scanf("%d", &val);
        printf("Position: ");
        scanf("%d", &pos);
        success = insertNode(head, val, pos);
        if (success == 0) printf("\nPosition exceeds list length.\n");
        else printf("\nNode successfully inserted.\n");
        break;
      case 4:
        popNode(head);
        break;
      case 5:
        printf("Data value to look for: ");
        scanf("%d", &val);
        success = removeNode(head, val);
        if (success == 0) printf("\nNode with value could not be found.\n");
        else printf("\nNode successfully removed.\n");
        break;
      case 6:
        printf("Position 1: ");
        scanf("%d", &pos);
        printf("Position 2: ");
        scanf("%d", &pos2);
        success = swapNodes(head, pos, pos2);
        if (success == 0) printf("\nError, couldn't swap.\n");
        else printf("\nNodes successfully swapped.\n");
        break;
      case 7:
        printList(head);
        break;
      case 8:
        deleteList(head);
        printf("List deleted. Exiting.\n");
        exit(0);
        break;
    }
  }
}

int main() {
  Node *head = createHead();
  while (1) {
    printMenu(head);
  }
  return 0;
}