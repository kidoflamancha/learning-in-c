/*************************************************************************
	> File Name: malloc-test.c
	> Author: Matt Joiner
	> From: https://stackoverflow.com/questions/3463207/how-big-can-a-malloc-be-in-c
	> Mail: 
	> Created Time: Wed 28 Feb 2018 10:05:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void *malloc_wrap(size_t size)
{
    void *p = malloc(size);
    if (p) {
        printf("Allocated %zu bytes from %p to %p\n", size, p, p + size);
    }
    else {
        printf("Failed to allocated %zu bytes\n", size);
    }
    return p;
}

int main(void)
{
    size_t step = 0x1000000;
    size_t size = step;
    size_t best = 0;
    while (step > 0)
    {
        void *p = malloc_wrap(size);
        if (p) {
            free(p);
            best = size;
        }
        else {
            step /= 0x10;
        }
        size += step;
    }
    void *p = malloc_wrap(best);
    if (p) {
        pause();
        return 0;
    }
    else {
        return 1;
    }
}
