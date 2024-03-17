#include "stdio.h"
#include "stdlib.h"
#include<sys/time.h>

long long timeInMilliseconds(void);

int main(void) {

    long long start = timeInMilliseconds();

    FILE *f = fopen("words.txt", "r");

    int ret;
    ret = fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    ret = fseek(f, 0, SEEK_SET);

    char *string = malloc(fsize + 1);
    ret = fread(string, fsize, 1, f);
    fclose(f);

    string[fsize] = 0;

    char *temp = string;
    int newlines = 0;
    while (*temp != '\0') {
        if (*temp == '\n') {
            newlines++;
        }
        temp++;
    }

    long long end = timeInMilliseconds();

    printf("Total Time: %lld ms\n", (end - start));

    return 0;
}

long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}