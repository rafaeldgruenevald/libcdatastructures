#ifndef SINGLY_LINKEDLIST_H
#define SINGLY_LINKEDLIST_H

typedef struct Node {
  int val;
  struct Node *next;
} Node;

int listLength(Node *node);

int addNode(Node **node, int pos, int val);

int modNode(Node **node, int pos, int val);

int removeNode(Node **node, int pos);

int returnNode(Node *node, int pos);

#endif