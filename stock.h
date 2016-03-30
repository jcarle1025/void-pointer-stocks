#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

typedef struct stock{
	char * stockSymbol;
	float closingSharePrice;
	float openingSharePrice;
	int numberOfShares;
	float (* getPrice)(void * S);
	float (* getTotalDollarAmount)(void * S);
	float (* getPercentChange)(void * S);
	void (* toString)(void * S);
}stock_t;

typedef stock_t * stock;

void * makeStock(char * line);
void * createStock(char *sym, float close, float open, int shares);
float sGetPrice(void * S);
float sGetDollarAmount(void * S);
float sGetPercentChange(void * S);
void sToString(void * S);
char * returnLine(FILE *fp);