#include <stdlib.h>
#include <stdio.h>
#include "bf-interpreter.h"

#define ARR_SIZE 30000

int arr[ARR_SIZE];
int ptr = 0;

node_t *start;

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

void push(node_t new, node_t *current){
    if(current == NULL){
        *current = new;
    }
    else if(current->next == NULL){
        current->next = &new;
    }
    else{
        push(new, current->next);
    }
}

node_t pop(node_t *current){
    if(current == NULL){
        return *current;
    }
    else if(current->next == NULL){
        node_t copy = *current;
        current = NULL;
        return copy;
    }
    else{
        pop(current->next);
    }
}