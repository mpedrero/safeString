#ifndef SAFESTRING_H
#define SAFESTRING_H

#include <string.h>

#define SAFESTRING_TRUE 1
#define SAFESTRING_FALSE 0

#define STR_CLEAR(str) do { strClear(str, sizeof(str)); } while(0)
#define IS_STR(str) (isStr(str, sizeof(str)))
#define IS_EQUAL(str1, str2) \
({                                      \
    int ret;                            \
    if (IS_STR(str1) && IS_STR(str2))   \
        ret = isEqual(str1, str2);      \
    else                                \
        ret = 0;                        \
    (ret);                              \
})

#define SAFE_STR_CPY(dest, src)                    \
({                                                 \
    int ret;                                       \
    if (IS_STR(src))                               \
        ret = safeStrCpy(dest, src, sizeof(dest)); \
    else                                           \
        ret = 0;                                   \
    (ret);                                         \
})

#define SAFE_STR_CAT(dest, src)                    \
({                                                 \
    int ret;                                       \
    if (IS_STR(dest) && IS_STR(src))               \
        ret = safeStrCat(dest, src, sizeof(dest)); \
    else                                           \
        ret = 0;                                   \
    (ret);                                         \
})


/* Fill str with zeros, thus making a string of length 0 */
void strClear(char* str, int size){
    memset(str, '\0', size);
}


/* Return 1 if a is a string, or 0 otherwise */
int isStr(char* str, int size)
{
    for(int i=0;i<size;i++){
        if(str[i] == '\0'){
            return SAFESTRING_TRUE;
        }
    }
    return SAFESTRING_FALSE;
}


/* Return 1 if str1 is equal to str2, or 0 otherwise */
int isEqual(char* str1, char* str2){
    if(strcmp(str1, str2) == 0){
        return SAFESTRING_TRUE;
    }
    return SAFESTRING_FALSE;
}


/* Copy the maximum possible characters of src string into dest
 * Returns 1 if the entire src string has been copied, or 0 otherwise*/
int safeStrCpy(char* dest, char* src, int size_dest){
    size_dest -= 1;
    strncpy(dest, src, size_dest);

    if(strlen(src) > size_dest){
        return SAFESTRING_FALSE;
    }
    return SAFESTRING_TRUE;
}


/* Concatenate the maximum possible characters of src string into dest
 * Returns 1 if the entire src string has been concatenated, or 0 otherwise*/
int safeStrCat(char* dest, char* src, int size_dest){
    size_dest -= 1;
    int chars_left = size_dest - strlen(dest);

    strncat(dest, src, chars_left);

    if (strlen(src) > chars_left){
        return SAFESTRING_FALSE;
    }
    return SAFESTRING_TRUE;
}

#endif
