#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

typedef struct node{
	void * item;
	struct node *next;
	struct node *prev;
}node_t;

typedef struct doubleLL{
	node_t *headNode;
	node_t *lastNode;
}doubleLL_t;

typedef doubleLL_t * doubleLL;
typedef node_t * node;

doubleLL makeDLL();
node createNode(void *data);
void insert(doubleLL myDLL, void *pItem);
void deleteNode(doubleLL myDLL, void *delItem);
void traverse(doubleLL myDLL);
void reverseTrav(doubleLL myDLL);
void * returnItem(node takeFrom);
node findLast(doubleLL myDLL);
int getSize(doubleLL myDLL);

