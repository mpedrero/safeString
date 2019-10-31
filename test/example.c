#include <stdio.h>
#include <stdlib.h>
#include "../src/safeString.h"

int main(void)
{
    char str1[] = "Hello";
    char str2[] = ", world.";
    char str3[3];
    char* str10 = malloc(10*sizeof(char));
    char str100[100];

    printf("str1: \"%s\"\n", str1);
    printf("str2: \"%s\"\n", str2);
    printf("\n");

    printf("Return value for copying \"%s\" into a smaller string of size %ld: %d\n", str1, sizeof(str3), safeStrCpy(str3, str1, sizeof(str3)));
    printf("Value of the copied string: \"%s\"\n", str3);
    printf("Length of the copied string: \"%ld\"\n", strlen(str3));
    printf("\n");
    
    printf("Return value for copying \"%s\" into a larger string of size %ld: %d\n", str1, sizeof(str10), safeStrCpy(str10, str1, sizeof(str10)));
    printf("Value of the copied string: \"%s\"\n", str10);
    printf("Length of the copied string: \"%ld\"\n", strlen(str10));
    printf("\n");

    printf("Return value for concatenating \"%s\" and \"%s\" into a smaller string of size %ld: %d\n", str1, str2, sizeof(str10), safeStrCat(str10, str2, sizeof(str10)));
    printf("Value of the copied string: \"%s\"\n", str10);
    printf("Length of the copied string: \"%ld\"\n", strlen(str10));
    printf("\n");

    safeStrCpy(str100, str1, sizeof(str100));
    printf("Return value for concatenating \"%s\" and \"%s\" into a smaller string of size %ld: %d\n", str1, str2, sizeof(str100), safeStrCat(str100, str2, sizeof(str100)));
    printf("Value of the copied string: \"%s\"\n", str100);
    printf("Length of the copied string: \"%ld\"\n", strlen(str100));
    printf("\n");
    
    return 0;
}