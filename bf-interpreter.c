#include <stdlib.h>
#include <stdio.h>
#include "bf-interpreter.h"

#define ARR_SIZE 30000

int arr[ARR_SIZE];
int ptr = 0;


int main(int argc, char **argv){
    if(argc < 2){
        printf("No path to BF file.");
        return 1;
    }
    if(argc > 3){
        printf("Too many arguments passed.");
        return 1;
    }

    FILE *bf;
    FILE *in;
    if(argc == 3){
        in = fopen(argv[2], "r");
    }

    bf = fopen(argv[1], "r");
    char c;
    c = fgetc(bf);
    while(c != EOF){
        if(c == '+'){
            arr[ptr]++;
        }
        else if(c == '-'){
            arr[ptr]--;
        }
        else if(c == '>'){
            ptr++;
        }
        else if(c == '<'){
            ptr--;
        }
        else if(c == '.'){
            printf("%c", arr[ptr]);
        }
        else if(c == ','){
            arr[ptr] = fgetc(in);
        }
        else if(c == '['){
            if(arr[ptr] == 0){
                while(1){
                    if(fgetc(bf) == ']') break;
                }
            }
        }
        else if(c == ']'){
            if(arr[ptr] != 0){

            }
        }
        c = fgetc(bf);
    }

    printf("\n");
    fclose(bf);
    return 0;
}