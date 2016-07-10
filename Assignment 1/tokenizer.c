#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_delim(char x, char* delimiters){
   int size = strlen(delimiters);
	bool is = false;
	for (int j=0;j<size;++j){
		if(x==delimiters[j]){
			is=true;
		}
	}
	return(is);
}

int numnew(char* line){
	int size=strlen(line);
	int count=0;
	for(int i=0;i<size;i++){
		if(line[i]=='\n'){
			count=count+1;
		}
	}
	return(count);
}

char* find_token(char* line, int pos, char* delimiters){
	int count=0;
   char* wrd_buf;
	int i=pos;
	while(!is_delim(line[i], delimiters)){
		if (line[i]!='\n'){
			count=count+1;
		}
		i=i+1;
	}
   wrd_buf=(char*)malloc(sizeof(char)*(count+1));
   i=pos;
	for(i=0;i<count;++i){
	   if(line[i+pos]!='\n'){
		   wrd_buf[i]=line[i+pos];
	   }
	   else{
		   wrd_buf[i]=0;
	   }
	}
	wrd_buf[count]='\0';
	return(wrd_buf);
}

char **tokenize( char *line, char *delimiters){
	bool prev_delim=true;
	bool cur_delim;
	int size=strlen(line)-numnew(line);
	int tcount=0;
	int i, j;
	for (i=0; i<size; ++i){
		 cur_delim=is_delim(line[i], delimiters);
		 if (prev_delim&&!cur_delim){
			 tcount=tcount+1;
		 }
		 prev_delim=cur_delim;
	}
	char** retvals=(char **)malloc(sizeof(char*)*(1+tcount));
   i=0;
	j=0;
	prev_delim=true;
	while(i<size){
      cur_delim=is_delim(line[i], delimiters);
		if(prev_delim && !cur_delim){
         retvals[j]=find_token(line, i, delimiters);
			i=i+strlen(retvals[j]);
			j=j+1;
		}
		else{
			i=i+1;
		}
	}
	retvals[size]='\0';
	return(retvals);
}      
