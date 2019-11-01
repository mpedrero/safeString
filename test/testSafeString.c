#include "../src/safeString.h"
#include <stdio.h>
#include <assert.h>

int main(void)
{
    char str1[] = "Hello";
    char str2[] = ", world";
    char strGoodDest[100];
    char strBadDest[3];
    char notStr[10];
    memset(notStr, 1, sizeof(notStr));
    strClear(strGoodDest, sizeof(strGoodDest));
    strClear(strBadDest, sizeof(strBadDest));
    
    /* Function tests */

    /* isStr tests */
    assert(isStr(str1, sizeof(str1)));
    assert(isStr(str2, sizeof(str2)));
    assert(isStr(strGoodDest, sizeof(strGoodDest)));
    assert(isStr(strBadDest, sizeof(strBadDest)));
    assert(!isStr(notStr, sizeof(notStr)));

    /* isEqual tests */
    assert(isEqual(str1, str1));
    assert(!isEqual(str1, str2));

    /* safeStrLen tests */
    assert(safeStrLen(str1, sizeof(str1)) == strlen(str1));
    assert(safeStrLen(notStr, sizeof(notStr)) == 0);

    /* safeStrCpy tests */
    assert(safeStrCpy(strGoodDest, str1, sizeof(strGoodDest)));
    assert(!safeStrCpy(strBadDest, str1, sizeof(strBadDest)));
    assert(isEqual(strGoodDest, str1));
    assert(!isEqual(strBadDest, str1));
    assert(isStr(strGoodDest, sizeof(strGoodDest)));
    assert(isStr(strBadDest, sizeof(strBadDest)));

    /* safeStrCat tests */
    safeStrCpy(strGoodDest, str1, sizeof(strGoodDest));
    safeStrCpy(notStr, str1, sizeof(notStr));
    assert(safeStrCat(strGoodDest, str2, sizeof(strGoodDest)));
    assert(!safeStrCat(notStr, str2, sizeof(notStr)));
    assert(isStr(strGoodDest, sizeof(strGoodDest)));
    assert(isStr(notStr, sizeof(notStr)));
    assert(strlen(str1)+strlen(str2) == strlen(strGoodDest));
    assert(strlen(str1)+strlen(str2) != strlen(notStr));

    /* Macros tests */
    SAFE_STR_CPY(str1, "Hello");
    SAFE_STR_CPY(str2, ", world");
    memset(notStr, 1, sizeof(notStr));
    STR_CLEAR(strGoodDest);
    STR_CLEAR(strBadDest);

    /* IS_STR tests */
    assert(IS_STR(str1));
    assert(IS_STR(str2));
    assert(IS_STR(strGoodDest));
    assert(IS_STR(strBadDest));
    assert(!IS_STR(notStr));

    /* IS_EQUAL tests */
    assert(IS_EQUAL(str1, str1));
    assert(!IS_EQUAL(str1, str2));

    /* SAFE_STR_LEN tests */
    assert(SAFE_STR_LEN(str1) == strlen(str1));
    assert(SAFE_STR_LEN(notStr) == 0);

    /* SAFE_STR_CPY tests */
    assert(SAFE_STR_CPY(strGoodDest, str1));
    assert(!SAFE_STR_CPY(strBadDest, str1));
    assert(IS_EQUAL(strGoodDest, str1));
    assert(!IS_EQUAL(strBadDest, str1));
    assert(IS_STR(strGoodDest));
    assert(IS_STR(strBadDest));

    /* SAFE_STR_CAT tests */
    SAFE_STR_CPY(strGoodDest, str1);
    SAFE_STR_CPY(notStr, str1);
    assert(SAFE_STR_CAT(strGoodDest, str2));
    assert(!SAFE_STR_CAT(notStr, str2));
    assert(IS_STR(strGoodDest));
    assert(IS_STR(notStr));
    assert(strlen(str1)+strlen(str2) == strlen(strGoodDest));
    assert(strlen(str1)+strlen(str2) != strlen(notStr));   

    printf("All tests passed\n");
    return 0;
}