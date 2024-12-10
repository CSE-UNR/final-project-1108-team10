// Derek Stone, Zachary, Foster, Miles Zeller
// 12/10/2024
// CS 135
// Final Lab Project

#include <stdio.h>
#define STRING_CAPACITY 100
#define WORD_CAP 30
#define FILE_NAME "madlib2.txt"

//function prototypes
void arrayLength(FILE* fptr, int* length);
void fillArray(int length, char data[][STRING_CAPACITY], FILE* fptr);
void addWords(char data[][STRING_CAPACITY], int length);
void grabUserWord(char letter, char word[WORD_CAP]);
void print2DArray(int num_rows, char data[][STRING_CAPACITY]);


int main(){
	
	FILE *fptr;
	fptr = fopen(FILE_NAME, "r");
	if(fptr == NULL){
		printf("Can't open file");
		return 0;
	}	

	int length = 0;
	arrayLength(fptr, &length);
	char data[length][STRING_CAPACITY];
	fclose(fptr); 

	fptr = fopen(FILE_NAME, "r");
	if(fptr == NULL){
		printf("Can't open file");
		return 0;
	}
	
	fillArray(length, data, fptr);
	addWords(data, length);
	print2DArray(length, data);
	   
	return 0;
}



void arrayLength(FILE* fptr, int* length){
	char line[STRING_CAPACITY];
	while (fgets(line, STRING_CAPACITY, fptr) != 0){
		(*length)++;
	}
}


void fillArray(int length, char data[][STRING_CAPACITY], FILE* fptr){
	for(int row = 0; row <= length; row++){
		fgets(data[row], STRING_CAPACITY, fptr);
		for(int col = 0; data[row][col] != '\0'; col++){
        		if (data[row][col] == '\n'){
        			data[row][col] = ' ';
			}
		}
	}
}


void addWords(char data[][STRING_CAPACITY], int length){
	for (int row = 0; row < length; row++){
		if (data[row][2] == '\0'){
			grabUserWord(data[row][0], data[row]);
		}
	}
}


void grabUserWord(char letter, char word[WORD_CAP]){
	switch(letter){
		case 'A':
			printf("Give me an adjective: ");
			fgets(word, STRING_CAPACITY, stdin);
			break;
		case 'N':
			printf("Give me a noun: ");
			fgets(word, STRING_CAPACITY, stdin);
			break;
		case 'V':
			printf("Give me a verb: ");
			fgets(word, STRING_CAPACITY, stdin);
			break;

	}
}


//Print Madlibs
void print2DArray(int num_rows, char data[][STRING_CAPACITY]){
	for(int row = 0; row < num_rows; row++){
		for(int col = 0; data[row][col] != '\0'; col++){
			if (data[row][col] != '\n'){
        			printf("%c", data[row][col]);
        		}else{
        			if (data[row+1][0] != '!' && data[row+1][0] != '?' && data[row+1][0] != '.'){
        				printf(" ");
        			}
        		}
    		}
	}
	printf("\n");
}


