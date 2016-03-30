#include "doubleLinkedList.h"

doubleLL makeDLL(){
	doubleLL myDLL;
	myDLL = (doubleLL)malloc(sizeof(doubleLL_t));
	
	myDLL->headNode = NULL;
	myDLL->lastNode = NULL;

	return myDLL;
}

node createNode(void *data){
	node myNode = malloc(sizeof(node));
	myNode->prev = NULL;
	myNode->next = NULL;
	myNode->item = data;
	return myNode;
}

void insert(doubleLL myDLL, void *pItem){
	node newNode;
	newNode = createNode(pItem);

	if(myDLL->headNode == NULL){
		myDLL->headNode = newNode;
		myDLL->lastNode = newNode;
	}

	else {
	newNode->prev = myDLL->lastNode;
	newNode->next = NULL;
	myDLL->lastNode->next = newNode;
	myDLL->lastNode = newNode;
	}
}

void deleteNode(doubleLL myDLL, void *delItem){
	node tempList;
	tempList = myDLL->headNode;
	node temp;
	node temp2;

	if(getSize(myDLL) == 1 && tempList->item == delItem){
		free(myDLL);
		doubleLL another = makeDLL();
	}

	else{
		if(tempList->item == delItem){
			temp = tempList->next;
			free(tempList);
			temp->prev = NULL;
			myDLL->headNode = temp;
		}

		tempList = tempList->next;
		while(tempList->next != NULL){
			if(tempList->item == delItem){
				temp = tempList->prev;
				temp2 = tempList->next;
				free(tempList);
				temp->next = temp2;
				temp2->prev = temp;
			}
			tempList = tempList->next;
		}

		tempList = myDLL->lastNode;
		if(tempList->item == delItem){
			temp = tempList->prev;
			free(tempList);
			temp->next = NULL;
			myDLL->lastNode = temp;
		}
	}
}

void traverse(doubleLL myDLL){
	node temp;
	temp = myDLL->headNode;

	if(temp == NULL)
		printf("EMPTY LIST\n\n");

	else{
		printf("Traversing...\n{");
		while(temp->next != NULL){
			printf("%c, ", *((char*)returnItem(temp)));
			temp = temp->next;
		}

		printf("%c}\n", *((char*)returnItem(temp)));
	}
}

void reverseTrav(doubleLL myDLL){
	node temp;
	temp = myDLL->lastNode;

	if(temp == NULL)
		printf("EMPTY LIST\n\n");

	else{
		printf("Traversing backwards...\n{");
		while(temp->prev != NULL){
			printf("%c, ", *((char*)returnItem(temp)));
			temp = temp->prev;
		}

		printf("%c}\n", *((char*)returnItem(temp)));
	}
}

/*void eraseList(doubleLL myDLL){
	node temp, temp2;
	temp = myDLL->lastNode;

	while(temp->prev != NULL){
		temp2 = temp->prev;
		deleteNode(myDLL, temp);
		temp = temp2;
	}
	deleteNode(myDLL, temp);
}*/

void * returnItem(node takeFrom){
	return takeFrom->item;
}

node findLast(doubleLL myDLL){
	node last;
	last = myDLL->lastNode;
	return myDLL->lastNode;
}

int getSize(doubleLL myDLL){
	int size = 0;
	node temp = myDLL->headNode;

	if(temp == NULL)
		return size;

	while(temp->next != NULL){
		size ++;
		temp = temp->next;
	}
	return size+1;
}