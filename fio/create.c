#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a file 
int main(int argc, char * argv[])
{
    int fsize = atoi(argv[1]);
    printf("file size is %dM\n", fsize);

    FILE *file_to_write = fopen("test", "wb");

    // char fill = 0xff;
    char fill[1024] = {0x0};
    memset(fill, 0xff, sizeof(fill));
    printf("size of char is %lu\n", sizeof(fill));
    size_t wsize = 0;
    long i = 0;
    for (i = 0; i < fsize*1024; i++) {
        // 1kb per loop
        wsize += fwrite(&fill, sizeof(fill), 1, file_to_write);
    }

    printf("write size is %lu Bytes\n", wsize);

    fclose(file_to_write);
    return 0;
}