#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "geometry.h"


#define TRIANGLE 1
#define CIRCLE 2


int Parser(Figure *new, char *A)
{
  char B[256];
  int i = 0;
  while (A[i] >= 'a' && A[i] <= 'z')
  {
    B[i] = A[i];
    i++;
  }
  B[i] = '\0';
  if (!(strcmp(B, "triangle")))
  {
    new->type = TRIANGLE;
  }
  else if (!(strcmp(B, "circle")))
  {
    new->type = CIRCLE;
  }
  else
  {
    printf("Unknown type\n");
    return 1;
  }
  char *end;
  end = A;
  i = -1;
  new->coordinates = (double *)malloc(sizeof(double) * 100);
  if (new->coordinates == NULL)
  {
    printf("Error");
    return 1;
  }
  while (*A)
  {
    new->coordinates[i] = strtod(A, &end);
    A = end;
    i++;
    while (!(isdigit(*A) || *A == '-' || *A == '+') && *A)
    {
      A++;
    }
  }
  new->size = i;
  return 0;
}


