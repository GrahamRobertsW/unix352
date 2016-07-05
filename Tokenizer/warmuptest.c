/*
 * warmuptest.c
 * 
 * test program for the tokenize() function declared in tokenizer.h
 * 
 * David Bover, June 2016
 */

#include <stdio.h>
#include "tokenizer.h"

#define MAX_LINE 1024

int main() {

	char line[MAX_LINE];
	char **tokens;
	int i;

	//for each line of input from stdin
	while (fgets(line, MAX_LINE, stdin)) {
		
		// break up the line into tokens
		tokens = tokenize(line, " .,;\t");
		
		// display each token
		for (i = 0; tokens[i]; i++)
			printf("token: '%s'\n", tokens[i]);
	}

	return 0;
}