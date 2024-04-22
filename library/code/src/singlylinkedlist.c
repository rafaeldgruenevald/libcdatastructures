#include <stdlib.h>
#include "include/singlylinkedlist.h"

int listLength(Node *node) {
    int tam = 1; 
    Node *tempNode = node;
    if (node == NULL) {
        return 0;
    }
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
        tam++;
    }
    return tam;
}

int addNode(Node **node, int pos, int val) {
    int tam = listLength(*node);
    Node *prevNode = *node;
    Node *nextNode = *node;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    if (pos > tam) {
        return -1;
    }
    if (pos == -1) {
	if (*node == NULL) {
	    newNode->next = NULL;
	    *node = newNode;
	} else {
	    Node *tempNode = *node;
	    while (tempNode->next != NULL) {
            tempNode = tempNode->next;
	    }
	    tempNode->next = newNode;
	}
	return 1;
    }
    for (int i = 1; i < pos; i++) {
        prevNode = prevNode->next;
    }
    if (pos == 0) {
        newNode->next = prevNode;
        *node = newNode;
        return 1;
    } 
    nextNode = prevNode->next;
    prevNode->next = newNode;
    newNode->next = nextNode;
    return 1;
}

int modNode(Node **node, int pos, int valor) {
    int tam = listLength(*node);
    Node *modNode = *node;
    if (pos > tam || pos < 0) {
        return -1;
    }
    for (int i = 0; i < pos; i++) {
        modNode = modNode->next;
    }
    modNode->val = valor;
    return 1;
}

int removeNode(Node **node, int pos) {
    int tam = listLength(*node);
    Node *prevNode = *node;
    Node *nextNode;
    if (pos > tam || pos < 0) {
        return -1;
    }
    // Remove Head
    if (pos == 0) {
        nextNode = nextNode->next;
        free(*node);
        *node = nextNode;
        return 1;
    }
    for (int i = 1; i < pos; i++) {
        prevNode = prevNode->next;
    }
    nextNode = (prevNode->next)->next;
    free(prevNode->next);
    // Remove Tail or value in the middle
    if(pos == (tam - 1)) {
        prevNode->next = NULL;
    } else {
        prevNode->next = nextNode;
    }
    return 1;
}

int returnNode(Node *node, int pos) {
    int tam = listLength(node);
    Node *tempNode = node;
    if (pos > tam || pos < 0) {
	return -1;
    }
    for (int i = 0; i < pos; i++) {
	tempNode = tempNode->next;
    }
    return tempNode->val;
}