# safeString
_safeString_ is a small header which comprises several functions intended to
perform common operations with C strings in an easier and safer way. It also
contains equivalent macros that provide a simpler interface.

# How to use
Include `safeString.h` in your code. That's it.

All functions and macros return 1 in case of a successful execution, or 0
otherwise (except `strClear`). Thus, it is easy to test whether the operation has been done as
intended.

# Functions

Note that `char*` parameters must _not_ receive an uninitialized pointer, but an
array. Also note that the size of a dynamic array _can not_ be obtained by using
`sizeof()` function, so it must be set explicitly.

* `void strClear(char* str, int size)`: Fills `str` with `\0` within `size`,
  thus making a string of length 0.
* `int isStr(char* str, int size)`: Checks if `str` is a valid string within
  `size`. Returns 0 otherwise.
* `int isEqual(char* str1, char* str2)`: Returns 1 if `str1` is equal to `str2`,
  or 0 otherwise. Both `str1` and `str2` _must_ be valid strings.
* `int safeStrCpy(char* dest, char* src, int size_dest)`: Copies the maximum
  possible characters of `src` string into `dest`. Returns 1 if _the entire_
  `src` string has been copied, or 0 otherwise. `src` _must_ be a valid string.
* `int safeStrCat(char* dest, char* src, int size_dest)`: Concatenates the
  maximum possible characters of `src` string after `dest` string. Returns 1 if
  _the entire_ `src` string has been concatenated, or 0 otherwise. Both `src`
  and `dest` _must_ be valid strings.

# Macros

These macros __are compatible only with static strings__. They provide a simpler
interface for the functions above without the need of size information.

* `STR_CLEAR(str)`
* `IS_STR(str)`
* `IS_EQUAL(str1, str2)`
* `SAFE_STR_CPY(dest, src)`
* `SAFE_STR_CAT(dest, src)`

# Dependencies

The only requirement for safeString is `string.h`, which should be already
installed of most C environments.

# Example of use
A more comprehensive code can be found on `test/example.c`

```c
#include "safeString.h"
#include <stdio.h>

int main(void)
{
    char str1[] = "Hello";
    char str2[] = ", world";
    char small[10];
    char large[100];

    STR_CLEAR(small);
    SAFE_STR_CAT(small, str1);
    SAFE_STR_CAT(small, str2);

    SAFE_STR_CPY(large, str1);
    SAFE_STR_CAT(large, str2);

    printf("small: %s\nlarge: %s\n", small, large);

    return 0;
}
```