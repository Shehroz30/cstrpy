#include <string.h>
#include <sys/types.h>
#include <stdbool.h>
void revstr(char *str)  
{
    int i;
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
} 

