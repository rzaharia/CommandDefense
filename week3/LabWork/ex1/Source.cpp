#include "Allocator.h"
#include <cstdio>

int main()
{
    Allocator alloc(16 * 1024);
    unsigned* u = alloc.alloc(5u);
    int* i      = alloc.alloc(6);
    float* f    = alloc.alloc(7.0f);
    double* d   = alloc.alloc(8.0);
    char* c     = alloc.alloc('a');
    char* s     = alloc.alloc("abc");

    printf("unsigned: %u\nint: %d\nfloat: %g\ndouble: %g\nchar: %c\nstring: %s\n", *u, *i, *f, *d, *c, s);
}