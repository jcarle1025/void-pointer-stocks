#include "stock.h"

void * createStock(char *sym, float close, float open, int shares){
	stock s = (stock)malloc(sizeof(stock_t));

	s->stockSymbol = sym;
	s->closingSharePrice = close;
	s->openingSharePrice = open;
	s->numberOfShares = shares;
	s->getPrice = sGetPrice;
	s->getTotalDollarAmount = sGetDollarAmount;
	s->getPercentChange = sGetPercentChange;
	s->toString = sToString;

	return s;
}

float sGetPrice(void * S){
	float price;
	stock s;
	s = (stock) S;
	price = s->closingSharePrice;
	return price;
}

float sGetDollarAmount(void * S){
	float dollarAmount;
	stock s;
	s = (stock) S;
	dollarAmount = (s->closingSharePrice * s->numberOfShares);
	return dollarAmount;
}

float sGetPercentChange(void * S){
	float change;
	stock s;
	s = (stock) S;
	change = (s->closingSharePrice - s->openingSharePrice) / s->openingSharePrice;
	return change;
}

void sToString(void * S){
	char *sym;
	stock myStock;
	myStock = (stock) S;
	sym = myStock->stockSymbol;

	printf("Stock: %s\n\t", (myStock->stockSymbol));
	printf("Opening Price: %f\n\t", myStock->openingSharePrice);
	printf("Closing Price: %f\n\t", myStock->closingSharePrice);
	printf("# Shares: %d\n", myStock->numberOfShares);
}

int test_eol(char a){
  if (a == '\n')
    return 1;
  else
    return 0;
}
int test_eof(char a){
  if (a == EOF)
    return 1;
  else
    return 0;
}

char * returnLine(FILE *fp){
  char c;
  char *line;
  int size = 0;
  line = NULL;
  line = realloc(line,sizeof(char));

  c = fgetc(fp); 

  if (test_eof(c)) 
    return NULL;

  while (!test_eol(c)){
    *(line+size) = c;
    size++;
    line = realloc(line,sizeof(char)* (size+1));
    c = fgetc(fp);
  }
  *(line+size) = '\0';
  
  return line;
}