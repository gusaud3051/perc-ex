#pragma once

#include "frac.h"

typedef struct vector {
  int is_frac;
  int size;
  Frac** valuesf;
} Vector;

Vector* vectorInit(int* arr, int size);
Vector* vectorfInit(Frac** arrf, int size);
void printVector(Vector* vec);
Vector* mvs(Vector* vec, int scal);

