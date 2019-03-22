#include "geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRIANGLE 1
#define CIRCLE 2

int main()
{
    FILE* myfile;
    myfile = fopen("Fig.txt", "r");
    if (myfile == NULL) {
        printf("No file\n");
        return 1;
    }
    printf("You input:\n");
    int capacity = 100;
    int size = 0;
    char arr[256];
    int i = 0;
    Figure* new = (Figure*)malloc(sizeof(Figure) * capacity);
    if (new == NULL) {
        printf("Alloceted error\n");
        return 1;
    }
    while ((arr[i++] = fgetc(myfile)) != EOF) {
        if (size < capacity) {
            if (arr[i - 1] == '\n') {
                arr[i - 1] = '\0';
                Parser(&new[size], arr);
                size++;
                i = 0;
            }
        } else {
            capacity *= 2;
            new = (Figure*)realloc(new, capacity * sizeof(double));
            if (new == NULL) {
                printf("Alloceted error\n");
                return 1;
            }
        }
    }
    int j;
    for (i = 0; i < size; i++) {
        if (new[i].type == CIRCLE) {
            printf("Figure circle\n");
        } else if (new[i].type == TRIANGLE) {
            printf("Figure triangle\n");
        }
        j = 0;
	printf("Coordinats: ");
	for(j=0; j<new[i].size; j++){
            printf("%.2f   ", new[i].coordinates[j]);
        }
	printf("\n");
    }
    return 0;
}
