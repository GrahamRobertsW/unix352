#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "price.h"
#include "tokenizer.h"
#include "price.c"
#include "tokenizer.c"

typedef struct fhash_st{
   char code[9];
	char title[64];
   price_t price;
	char category[16];
	int stock;
	int sales[12];
} fhash_t, *fh_ptr;

fhash_t product(char *line){
	int ind=0;
	int tok_num=0;
	int i;
	int dollars;
	int cents;
	fhash_t prod;
	char** tokens = tokenize(line, ". ;-");
   for (i=0; i<8; i++){
		prod.code[i]=tokens[tok_num][i];
   }
	prod.code[8]='\0';
   for (i=8; i<strlen(tokens[tok_num]); i++){
      prod.title[ind]=tokens[tok_num][i];
	   ind=ind+1;
	}
	tok_num=tok_num+1;
   while (!isdigit(tokens[tok_num][0])){
		prod.title[ind]=' ';
		ind=ind+1;
		for(i=0;i<strlen(tokens[tok_num]);i++){
			prod.title[ind]=tokens[tok_num][i];
			ind=ind+1;
		}
		tok_num=tok_num+1;
	}
	prod.title[ind]='\0';
	ind=ind+1;
   dollars=atoi(tokens[tok_num]);
	tok_num=tok_num+1;
	cents=atoi(tokens[tok_num]);
	tok_num=tok_num+1;
	price_t p=new_price(dollars,cents,0);
	prod.price=p;
   strcpy(prod.category, tokens[tok_num]);
	tok_num=tok_num+1;
	prod.stock=atoi(tokens[tok_num]);
	tok_num=tok_num+1;
	ind=0;
	for(i=0; i<12; i++){
      prod.sales[i]=atoi(tokens[tok_num]);
		tok_num=tok_num+1;
	}
	return(prod);
}
//FILE* create_hashfile(char *name){
//	FILE *hfile;
//	hfile=fopen(name, 'w+');
//	return(hfile);
//}

//FILE* open_hashfile(char *name){
//	FILE *hfile;
//	hfile=fopen(name, 'a+');
//	return(hfile);
//}


//void hashfile(){
//}
//
//void main(){
//}
