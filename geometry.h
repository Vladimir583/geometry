#ifndef GEOMETRY_H
#define GEOMETRY_H

typedef struct {
    int type;
    double* coordinates;
    int size;
} Figure;

int Parser(Figure* new, char* A);

#endif