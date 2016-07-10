#include "hashfile.c"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include "price.h"
//#include "tokenizer.h"
//#include "price.c"
//#include "tokenizer.c"

void main(){
   char *line="WL237870Tattersall Oxford Cloth Shirt   34.50 SHIRT  5  5  6  1  7 10  4  4  0  7  4  3  6";
	fhash_t prod = product(line);
	char** tokens=tokenize(line, ", .;-'");
//   char tokens[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','k'}};
   fprintf(stdout,"code: %s\n",prod.code);
	fprintf(stdout,"title: %s\n",prod.title);
	fprintf(stdout,"Price: $%d.%d\n",prod.price.dollars,prod.price.cents);
	fprintf(stdout,"Stock: %d\n",prod.stock);
	fprintf(stdout,"Category: %s\n", prod.category);
	fprintf(stdout,"sales: ");
	for(int i=0; i<12; i++){
		fprintf(stdout,"%d ",prod.sales[i]);
	}
	//write_price(stdout,"price: ",prod.price,"\n");
//	for(int i=0; i<strlen(tokens[0]); i++){
//	char *word = tokens[0];
//   for(int i=0;i<8;i++){
//      fprintf(stdout, "tokens[0] is %s\n", tokens[i]);
//	}
}
