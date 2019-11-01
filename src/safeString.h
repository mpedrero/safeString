#ifndef SAFESTRING_H
#define SAFESTRING_H

#include <string.h>

#define SAFESTRING_TRUE 1
#define SAFESTRING_FALSE 0

#define STR_CLEAR(str) ({ strClear(str, sizeof(str)); })
#define IS_STR(str) ({ isStr(str, sizeof(str)); })
#define IS_EQUAL(str1, str2) \
({                                      \
    int ret;                            \
    if (IS_STR(str1) && IS_STR(str2))   \
        ret = isEqual(str1, str2);      \
    else                                \
        ret = SAFESTRING_FALSE;         \
    (ret);                              \
})

#define SAFE_STR_CPY(dest, src)                    \
({                                                 \
    int ret;                                       \
    if (IS_STR(src))                               \
        ret = safeStrCpy(dest, src, sizeof(dest)); \
    else                                           \
        ret = SAFESTRING_FALSE;                    \
    (ret);                                         \
})

#define SAFE_STR_CAT(dest, src)                    \
({                                                 \
    int ret;                                       \
    if (IS_STR(dest) && IS_STR(src))               \
        ret = safeStrCat(dest, src, sizeof(dest)); \
    else                                           \
        ret = SAFESTRING_FALSE;                    \
    (ret);                                         \
})

#define SAFE_STR_LEN(str) ({ safeStrLen(str, sizeof(str)); })


/* Fill str with zeros, thus making a string of length 0 */
static inline void strClear(char* str, int size){
    memset(str, '\0', size);
}


/* Return 1 if str is a string, or 0 otherwise */
static inline int isStr(char* str, int size)
{
    for(int i=0;i<size;i++){
        if(str[i] == '\0'){
            return SAFESTRING_TRUE;
        }
    }
    return SAFESTRING_FALSE;
}


/* Return 1 if str1 is equal to str2, or 0 otherwise */
static inline int isEqual(char* str1, char* str2){
    if(strcmp(str1, str2) == 0){
        return SAFESTRING_TRUE;
    }
    return SAFESTRING_FALSE;
}


/* Copy the maximum possible characters of src string into dest.
 * Return 1 if the entire src string has been copied, or 0 otherwise */
static inline int safeStrCpy(char* dest, char* src, int size_dest){
    size_dest -= 1;
    strncpy(dest, src, size_dest);

    if(strlen(src) > size_dest){
        return SAFESTRING_FALSE;
    }
    return SAFESTRING_TRUE;
}


/* Concatenate the maximum possible characters of src string into dest.
 * Return 1 if the entire src string has been concatenated, or 0 otherwise */
static inline int safeStrCat(char* dest, char* src, int size_dest){
    size_dest -= 1;
    int chars_left = size_dest - strlen(dest);

    strncat(dest, src, chars_left);

    if (strlen(src) > chars_left){
        return SAFESTRING_FALSE;
    }
    return SAFESTRING_TRUE;
}

/* Return the length of a string. Return 0 if the array is not a string */
static inline int safeStrLen(char* str, int size)
{
    if(isStr(str, size)){
        return strlen(str);
    }
    return SAFESTRING_FALSE;
}

#endif
