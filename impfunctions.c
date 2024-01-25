#include "impfunctions.h"

void revstr(char *str)  
{
    unsigned int i;
    int j;
    unsigned char a;
    unsigned len = strlen((const char *)str);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
            a = str[i];
            str[i] = str[j];
            str[j] = a;
    }
}  
int startswith(char* str, char* substr) { 
    for (int i = 0; substr[i] != '\0'; i++) {
        if (str[i] != substr[i]) {
            return false;
        }
        return true;
    }
    return 0;
} 
int isPalindrome(char* str) {
    unsigned len = strlen((char *)str);
    for (int i = 0; i < len/2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

void removeDuplicates(char *str) { 
    char *cur = str; // pointer to char rn
    char *end = str;    // pointer to char at end of program

    //while not at end of string
    while (*cur) {
        char *runner = str;

        while (runner < cur) {
            if (*runner == *cur) {
                break;//breaks if there's a dupe
            }
            runner++;
        }

        if (runner == cur) {
            *end = *cur;
            end++;
        }

        cur++;
    }

    *end = '\0';
}

int containsString(char* str, char* substr) {
    return (strstr(str, substr) != NULL);
}

int isRotation(char* str1, char* str2) {
    unsigned len1 = strlen((char *)str1);
    unsigned len2 = strlen((char*)str2);
    if (len1 != len2) {
        return false;
    }
    char *concatenated = (char *)malloc(2 * len1 + 1);
    strcpy(concatenated, str1);
    strcat(concatenated, str1);

    // Check if s2 is a substring of the concatenated string
    int result = strstr(concatenated, str2) != NULL;

    // Free the allocated memory
    free(concatenated);

    return result;

}


void removeWhitespace(char *str) {
    char *rPtr = str;
    char *wPtr = str;
    while (*rPtr != '\0') {
        if (*rPtr != ' ') {
            *wPtr = *rPtr;
            wPtr++;
        }

        rPtr++;
    }
    *wPtr = '\0';
}
