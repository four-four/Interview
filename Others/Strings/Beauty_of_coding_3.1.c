#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
s1 = AABCD, s2 = CDAA
Return : true

给定两个字符串 s1 和 s2，要求判定 s2 是否能够被 s1 做循环移位得到的字符串包含。
*/

bool isRotatedSubString(const char *str1, const char *str2) {
    int len1 = 0, len2 = 0, len3 = 0, i = 0, j = 0;
    char *str3 = NULL, *curr = NULL:

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len2 > len1) {
        return false;
    }

    len3 = len1 * 2;

    str3 = (char *)malloc((len3 + 1) * sizeof(char));
    strncpy(str3, str1, len1);
    curr = str3 + len1;
    strncpy(curr, str1, len1);
    str3[len3] = '\0';

    for (i = 0; i < len3; i++) {
        if (*(str3 + i) == *str2) {
            for (j = 0; j < len2; j++) {
                if (i + j >= len3) {
                    return false;
                }
                if (*(str3 + i + j) != *(str2 + j)) {
                    break;
                }
            }
            if (j == len2) {
                return true;
            }
        }
    }

    free(str3);
}

int main() {
    char s1[6] = "AABCD";
    char s2[5] = "CADD";

    if (isRotatedSubString(s1, s2)) {
        printf("Success\n");
    } else {
        printf("Failed.\n");
    }
}