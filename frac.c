#include <stdio.h>
#include <stdlib.h>

#include "frac.h"

// basic function
int gcd(int a, int b) {
    int r = 1;
    while (r != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// frac 
Frac* divf(int a, int b) {
    if (b == 0) { printf("Cannot divide with 0.\n"); return 0; }
    
    Frac* f = (Frac*) malloc(sizeof(Frac));
    f->d = a;
    f->n = b;
    return f;
}

char* prtf(Frac* f) {
    char* str = (char*) malloc(sizeof(char) * 128);
    sprintf(str, "%d/%d", f->d, f->n);
    if (f->n == 1) sprintf(str, "%d", f->d);
    return str; // 제대로 된 출력이 되지 않는다면, 이곳을 먼저 변경할 것.
}

void invf(Frac* f) {
    if (f->d == 0) { printf("Cannot make inverse number with 0.\n"); return; }
    int tmp = f->d;
    f->d = f->n;
    f->n = tmp;
}

Frac* newinvf(Frac* f) {
    if (f->d == 0) { printf("Cannot make inverse number with 0.\n"); return 0; }
    
    return divf(f->n, f->d); // 이것은 새롭게 만들어내는 방법. f그 자체를 변환시키고 싶을땐...
}

Frac* plusf(Frac* f1, Frac* f2) { return divf(f1->d * f2->n + f2->d * f1->n, f1->n * f2->n);}

Frac* mulf(Frac* f1, Frac* f2) { return divf(f1->d * f2->d, f1->n * f2->n); }

void reduct(Frac* f) {
    int d = gcd(f->d, f->n);
    f->d /= d;
    f->n /= d;
}
