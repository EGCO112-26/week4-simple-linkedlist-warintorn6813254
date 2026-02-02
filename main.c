#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, char *argv[]) {

    typedef struct node Node;
    typedef Node* NodePtr;

    NodePtr head = NULL;
    NodePtr temp = NULL;

    int i;

    /* Insert each node using input argument */
    for (i = 1; i < argc; i += 2) {

        NodePtr newNode = (NodePtr) malloc(sizeof(Node));

        strcpy(newNode->id, argv[i]);
        strcpy(newNode->name, argv[i + 1]);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    /* Print all data in linked list */
    printf("print linked list\n");
    temp = head;
    while (temp) {
        printf("%s %s\n", temp->id, temp->name);
        temp = temp->next;
    }

    /* Delete all linked list */
    temp = head;
    while (temp) {
        head = head->next;
        free(temp);
        temp = head;
    }

    return 0;
}