#include "stock.h"
#include "doubleLinkedList.h"

int menu();

int main(){
	doubleLL myList;
	node lastNode, temp;
	stock s, s2, s3, s4;
	float dollars, price, change;
	char *sym, *line, *string;
	char *a, *b;
	float open, close, var;
	int shares;	

	myList = makeDLL();
	FILE *fp;

	fp = fopen("stocks", "r");
	if (fp == NULL){
		perror("Error opening file");
		return(-1);
	}
	
	sym = (char*)malloc(sizeof(char*));
	fscanf(fp, "%s %f %f %d", sym, &close, &open, &shares);

	s = createStock(sym, close, open, shares);
	insert(myList, s); 

	line = returnLine(fp);

	while(line != NULL){
		sym = (char*)malloc(sizeof(char*));
		fscanf(fp, "%s %f %f %d", sym, &close, &open, &shares);
		s = createStock(sym, close, open, shares);
		insert(myList, s);
		line = returnLine(fp);
	}
	fclose(fp);

	int choice = -1;

	choice = menu();
	while(choice!=5){
		switch(choice){
			case 1:
				puts("First Stock: ");
				temp = myList->headNode;
				s4 = (stock) temp->item;
				s4->toString(s4);
				break;

			case 2:
				puts("Stocks with closing price > :");
				scanf("%f", &var
			);
				printf("Your number is %f\n", var
			);

				for(temp = myList->headNode; temp->next != NULL; temp = temp->next){
					s4 = (stock) temp->item;
					if(s4->closingSharePrice > var
				)
						s4->toString(s4);
				}
				break;

			case 3:
				puts("Stocks with percent change > :");
				scanf("%f", &var
			);

				for(temp = myList->headNode; temp->next != NULL; temp = temp->next){
					s4 = (stock) temp->item;
					if(s4->getPercentChange(s4) > var
				)
						s4->toString(s4);
				}
				break;

			case 4:
				puts("Listing all stocks...");

				for(temp = myList->headNode; temp->next != NULL; temp = temp->next){
					s4 = (stock) temp->item;
					s4->toString(s4);
				}
				puts("Done printing.");

				break;
		}
		printf("\n");
		choice = menu();
	}
	puts("Goodbye");
	return 0;
}

int menu(){
	int uChoice;
	char c;
	puts("Please choose from the following...");
	puts("1. Print first stock. ");
	puts("2. Search/print stock with closing > some amount");
	puts("3. Search/print stock with percent change > some amount");
	puts("4. List all stocks");
	puts("5. Quit");

	scanf("%d%c", &uChoice, &c);
	return uChoice;
}