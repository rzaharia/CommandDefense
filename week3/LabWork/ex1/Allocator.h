#pragma once
class Allocator
{
    char* buffer;
    unsigned offset = 0;
    unsigned max_size;

    void* alloc_raw(unsigned size);

  public:
    Allocator(unsigned max_size);
    ~Allocator();

    unsigned* alloc(unsigned x);
    int* alloc(int x);
    float* alloc(float x);
    double* alloc(double x);
    char* alloc(char x);
    char* alloc(const char* string);
};
