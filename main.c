#include "geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRIANGLE 1
#define CIRCLE 2

int main()
{
    FILE* f1;
    f1 = fopen("Fig.txt", "r");
    if (f1 == NULL) {
        printf("No file\n");
        return 1;
    }
    int cap = 100, size = 0;
    char A[256];
    int i = 0;
    Figure* new = (Figure*)malloc(sizeof(Figure) * cap);
    if (new == NULL) {
        printf("Alloceted error\n");
        return 1;
    }
    while ((A[i++] = fgetc(f1)) != EOF) {
        if (size < cap) {
            if (A[i - 1] == '\n') {
                A[i - 1] = '\0';
                Parser(&new[size], A);
                size++;
                i = 0;
            }
        } else {
            cap *= 2;
            new = (Figure*)realloc(new, cap * sizeof(double));
            if (new == NULL) {
                printf("Alloceted error\n");
                return 1;
            }
        }
    }
    int j;
    for (i = 0; i < size; i++) {
        if (new[i].type == CIRCLE) {
            printf("Circle:\n");
        } else if (new[i].type == TRIANGLE) {
            printf("Triangle:\n");
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
