#pragma once

#include "vector.h"

typedef struct matrix {
    int row_size;
    int col_size;
    Vector** columns;
} Matrix;

Matrix* matrixInit(Vector** vecs, int rowsize);
void printMatrix(Matrix* mat);
Matrix* mms(Matrix* mat, int scal);
Vector* matCol(Matrix* mat, int col);
Vector* matRow(Matrix* mat, int row);
Matrix* matTrans(Matrix* mat);

