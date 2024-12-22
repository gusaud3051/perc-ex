#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "frac.h"


Vector* vectorInit(int* arr, int size) {
    Vector* vec = (Vector*) malloc(sizeof(Vector));
    vec->size = size;
    vec->valuesf = (Frac**) malloc(sizeof(Frac*) * size);
    for (int i = 0; i < size; i++) vec->valuesf[i] = divf(arr[i], 1);
    return vec;
}

Vector* vectorfInit(Frac** arrf, int size) {
    Vector* vec = (Vector*) malloc(sizeof(Vector));
    vec->size = size;
    vec->valuesf = (Frac**) malloc(sizeof(Frac*) * size);
    vec->valuesf = arrf;
    return vec;
}

void printVector(Vector* vec) {
    for (int i = 0; i < vec->size; i++) printf("%s ", prtf(vec->valuesf[i]));
    printf("\n---------------\n");
}

Vector* mvs(Vector* vec, int scal) {
    
  Frac** arrf = (Frac**) malloc(sizeof(Frac*) * vec->size);
    for (int i = 0; i < vec->size; i++) arrf[i] = mulf(vec->valuesf[i], divf(scal, 1));
    return vectorfInit(arrf, vec->size);
}

