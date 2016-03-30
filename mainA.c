#include "doubleLinkedList.h"

int main(){
	doubleLL myList;
	node lastNode;
	char *a, *b, *c, *d, *z;
	int size = 0;

	a = (char*)malloc(sizeof(char*));
	b = (char*)malloc(sizeof(char*));
	c = (char*)malloc(sizeof(char*));
	d = (char*)malloc(sizeof(char*));
	z = (char*)malloc(sizeof(char*));

	*a = 'A';
	*b = 'B';
	*c = 'C';
	*d = 'D';
	*z = 'Z';

	myList = makeDLL();

	insert(myList, z);
	traverse(myList);

	deleteNode(myList, z);
	size = getSize(myList);
	printf("Size: %d\n", size);
	traverse(myList);

	insert(myList, a);
	insert(myList, b);
	insert(myList, c);
	insert(myList, d);
	traverse(myList);
	reverseTrav(myList);
	size = getSize(myList);
	printf("Size: %d\n\n", size);

	deleteNode(myList, c);
	deleteNode(myList, a);
	traverse(myList);
	reverseTrav(myList);
	size = getSize(myList);
	printf("Size: %d\n", size);
	lastNode = findLast(myList);
	printf("Last Node: {%c}\n", *((char*)(returnItem(lastNode))));

	return 0;
}