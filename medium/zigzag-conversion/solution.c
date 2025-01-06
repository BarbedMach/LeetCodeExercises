#include <string.h>

char* convert(char* s, int numRows) {
    size_t len = strlen(s);
    char* result = (char*)malloc(len + 1);

    if (numRows == 1 || len <= numRows) {
        result = strcpy(result, s);
        return result;
    }

    size_t step = 2 * numRows - 2;

    for (size_t i = 0, j = 0; i < numRows; i++) {
        for (size_t k = i; k < len; k += step) {
            result[j++] = s[k];
            if (i > 0 && i < numRows - 1 && k + step - 2 * i < len) {
                result[j++] = s[k + step - 2 * i];
            }
        }
    }

    result[len] = '\0';
    return result;
}