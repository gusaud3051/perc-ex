#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "vector.h"

Matrix* matrixInit(Vector** vecs, int rowsize) {
    Matrix* mat = (Matrix*) malloc(sizeof(Matrix));
    mat->row_size = rowsize;
    mat->columns = (Vector**) malloc(sizeof(Vector*) * rowsize);
    
    int colsize = vecs[0]->size;
    for (int i = 0; i < rowsize; i++) {
        if (colsize == vecs[i]->size) {
            mat->columns[i] = vecs[i];
            continue;
        }
        printf("Cannot make this vectors as matrix. Each vectors has different size.\n");
        free(mat);
        return 0;
    }
    mat->col_size = colsize;
    return mat;
}

void printMatrix(Matrix* mat) {
    for (int i = 0; i < mat->row_size; i++) {
        printf("v%d : ", i);
        for (int j = 0; j < mat->col_size; j++) {
            printf("%d ", mat->columns[i]->values[j]);
        }
        printf("\n");
    }
	printf("---------------\n");
}

Matrix* mms(Matrix* mat, int scal) {
    Vector** vecs = (Vector**) malloc(sizeof(Vector*) * mat->row_size);
    for (int i = 0; i < mat->row_size; i++) vecs[i] = mvs(mat->columns[i], scal);
    return matrixInit(vecs, mat->row_size);
}

Vector* matCol(Matrix* mat, int col) { return mat->columns[col]; }

Vector* matRow(Matrix* mat, int row) {
    int* arr = (int*) malloc(sizeof(int) * mat->row_size);
    for (int i = 0; i < mat->row_size; i++) arr[i] = mat->columns[i]->values[row];
    return vectorInit(arr, mat->row_size);
}

Matrix* matTrans(Matrix* mat) {
    Vector** vecs = (Vector**) malloc(sizeof(Vector*) * mat->col_size);
    for (int i = 0; i < mat->col_size; i++) vecs[i] = matRow(mat, i);
    return matrixInit(vecs, mat->col_size);
}

