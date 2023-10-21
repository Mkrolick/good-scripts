#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} Node;

typedef struct list {
    int size;
    Node * head;
} List;

void addNode(List *list, int value) {
    Node * newNode = malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = list->head;
    list->head = newNode;
}

void deleteNode(Node *node, int value) {
    if (!(node->next)) {
       return;
    } else if (node->next->val == value) {
       Node * hold = node->next->next;
       free(node->next);
       node->next = hold;
    } else {
        deleteNode(node->next, value);
    }
}

void printList(Node * node){
    printf("%d ", node->val);
    if (node->next) printList(node->next);
}

int main() {
    
    List list = {4, NULL};
    addNode(&list, 10);
    addNode(&list, 20);
    addNode(&list, 30);
    addNode(&list, 40);
    printList(list.head);
    printf("\n");

    deleteNode(list.head, 30);
    printList(list.head);
    printf("\n");
}
