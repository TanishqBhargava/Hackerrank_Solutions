#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the crosswordPuzzle function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//
int find_length_down(char**crossword,int i,int j) {
    int new_i = i+1;
    while(new_i!=10&&crossword[new_i][j]=='-') {
        new_i++;
    }
    return new_i-i;
}
int find_length_right(char**crossword,int i,int j) {
    int new_j = j+1;
    while(new_j!=10&&crossword[i][new_j]=='-') {
        new_j++;
    }
    return new_j-j;
}

//place is vertical, or horizontal
int run_for_location(char** crossword, char** result, char* words, int location) {
    int word_length = 0;
    while(words[location+word_length]!=0&&words[location+word_length]!=';') {
        word_length++;
    }

    char** result2 = (char**)malloc(10*sizeof(char*));
    for(int i=0;i<10;i++) {
        result2[i] = (char*)malloc(10*sizeof(char));
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            result2[i][j] = result[i][j];
        }
    }

    

    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            if(crossword[i][j]=='-') {
                if(i==0||crossword[i-1][j]!='-') {
                    int length_down = find_length_down(crossword,i,j);
                    if(length_down==word_length){
                        int k;
                        for(k=0;k<word_length;k++){
                            if(result[i+k][j]=='-'||result[i+k][j]==words[location+k]){
                                result2[i+k][j]=words[location+k];
                            } else {
                                break;
                            }
                        }

                        if(k==word_length) {
                            if(words[location+word_length]==0) {
                                for(int i=0;i<10;i++) {
                                    for(int j=0;j<10;j++) {
                                        crossword[i][j] = result2[i][j];
                                    }
                                }
                                return 1;
                            }

                            if(run_for_location(crossword,result2,words,location+word_length+1)) {
                                return 1;
                            } else {
                                //
                            }
                        }
                            for(int i=0;i<10;i++) {
                                for(int j=0;j<10;j++) {
                                    result2[i][j] = result[i][j];
                                }
                            }
                        
                    }
                }
                //
                if(j==0||crossword[i][j-1]!='-') {
                    int length_right = find_length_right(crossword,i,j);              
                    if(length_right==word_length){
                        int k;
                        for(k=0;k<word_length;k++){
                            if(result[i][j+k]=='-'||result[i][j+k]==words[location+k]){
                                result2[i][j+k]=words[location+k];
                            } else {
                                break;
                            }
                        }

                        if(k==word_length) {
                            if(words[location+word_length]==0) {
                                for(int i=0;i<10;i++) {
                                    for(int j=0;j<10;j++) {
                                        crossword[i][j] = result2[i][j];
                                    }
                                }
                                return 1;
                            }

                            if(run_for_location(crossword,result2,words,location+word_length+1)) {
                                return 1;
                            } else {
                                //
                            }
                        }
                            for(int i=0;i<10;i++) {
                                for(int j=0;j<10;j++) {
                                    result2[i][j] = result[i][j];
                                }
                            }
                        
                    }

                }
                //
            }
        }
    }
    return 0;
}

char** crosswordPuzzle(int crossword_count, char** crossword, char* words, int* result_count) {
    // printf("HERE");
    char** result = (char**)malloc(10*sizeof(char*));
    for(int i=0;i<10;i++) {
        result[i] = (char*)malloc(10*sizeof(char));
    }
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
            result[i][j] = crossword[i][j];
        }
    }

    *result_count = crossword_count;
    run_for_location(crossword,result,words,0);
    return crossword;
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** crossword = malloc(10 * sizeof(char*));

    for (int i = 0; i < 10; i++) {
        char* crossword_item = readline();

        *(crossword + i) = crossword_item;
    }

    int crossword_count = 10;

    char* words = readline();

    int result_count;
    char** result = crosswordPuzzle(crossword_count, crossword, words, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}
