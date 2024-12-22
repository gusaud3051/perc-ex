#pragma once




// class Frac
typedef struct fraction {
    int d; // denominator;
    int n; // numerator;
}Frac;

Frac* divf(int a, int b);
char* prtf(Frac* f);
void invf(Frac* f);
Frac* newinvf(Frac* f);
Frac* plusf(Frac* f1, Frac* f2);
Frac* mulf(Frac* f1, Frac* f2);
void reduct(Frac* f);
