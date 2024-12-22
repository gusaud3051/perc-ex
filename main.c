#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "vector.h"
#include "matrix.h"
#include "frac.h"


// operator
Vector* pvv(Vector* v1, Vector* v2) {
    if (v1->size != v2->size) {
        printf("Cannot add vectors. Each vector has different size.\n");
        return 0;
    }
    
    Frac** arrf = (Frac**) malloc(sizeof(Frac*) * v1->size);
    for (int i = 0; i < v1->size; i++) {
        arrf[i] = plusf(v1->valuesf[i], v2->valuesf[i]); 
        reduct(arrf[i]);
    }
    return vectorfInit(arrf, v1->size);
}


Frac* mvv(Vector* v1, Vector* v2) {
    if (v1->size != v2->size) {
        printf("Cannot multiply vectors. Each vector has different size.\n");
        return 0;
    }
    
    Frac* res;
    res->d = 0;
    res->n = 1;
    for (int i = 0; i < v1->size; i++) 
        plusf(res, mulf(v1->valuesf[i], v2->valuesf[i])); 
    for (int i = 0; i < v1->size; i++) reduct(res);
    return res;
}


Vector* mmv(Matrix* m, Vector* v) {
    if (m->row_size != v->size) {
        printf("Cannot multiply this matrix and vector. Each matrix's row and vector has different size.\n");
        return 0;
    }
    
    Matrix* mat = matTrans(m);
    Frac** arrf = (Frac**) malloc(sizeof(Frac*) * m->col_size);
    for (int i = 0; i < m->col_size; i++) arrf[i] = mvv(mat->columns[i], v);
    return vectorfInit(arrf, m->col_size);
}

Matrix* mmm(Matrix* m1, Matrix* m2) {
    if (m1->row_size != m2->col_size) {
        printf("Cannot multiply this matrices. Each matrix' row and column has different size.\n");
        return 0;
    }
    
    Vector** vecs = (Vector**) malloc(sizeof(Vector*) * m2->row_size);
    for (int i = 0; i < m2->row_size; i++) vecs[i] = mmv(m1, m2->columns[i]);
    return matrixInit(vecs, m2->row_size);
}

int main()
{
	int arr[6] = {5, 4, 3, 2, 1, 0};
	
	int arr2[6] = {13, 11, 7, 5, 3, 2};
	
	Vector* vec = vectorInit(arr, 6);
	
	Vector* vec2 = vectorInit(arr2, 6);
	
  Frac** arrf = (Frac**) malloc(sizeof(Frac*) * 6);
  for (int i = 0; i < 6; i++) arrf[i] = divf(arr[i], arr2[i]);

  Vector* vec3 = vectorfInit(arrf, 6);

	Vector* vecs[6];
	
	for (int i = 0; i < 6; i++) vecs[i] = mvs(vec, i);
	Matrix* mat = matrixInit(vecs, 6);

  printf("vec : \n");
	printVector(vec);
  //printf("mat : \n");	
	//printMatrix(mat);
  printf("vec2 : \n");
	printVector(vec2);
  printf("vec3 : \n");
  printVector(vec3);
  printf("vec3 * vec1 : \n");
  printf("%s", prtf(mvv(vec3, vec)));
  printf("vec3 * vec2: \n");
  printf("%s", prtf(mvv(vec3, vec2)));
  printf("vec3 * vec3: \n");
  printf("%s", prtf(mvv(vec3, vec3)));
  //printf("mat^T : \n");	
	//printMatrix(matTrans(mat));
  //printf("mat * vec2 : \n");	
	//printVector(mmv(mat, vec2));
  //printf("mat * mat : \n");	
	//printMatrix(mmm(mat, mat));
  //printf("vec * vec2 : \n");	
	//printVector(pvv(vec, vec2));
  //printf("vec * 3 : \n");	
	//printVector(mvs(vec, 3));
  //printf("mat * 3 : \n");	
	//printMatrix(mms(mat, 3));
	//printf("%d\n", mvv(vec, vec2));
	return 0;
}

