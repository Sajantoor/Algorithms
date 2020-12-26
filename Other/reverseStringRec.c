#include <stdio.h> 
#include <string.h>

void str_reverse_rec(char *str) {
    int len = strlen(str);
     // stopping condition​
    if (len <= 1) {
        return;
    } else {
        char tmp = str[0]; // save str[0]  
        str[0] = str[len-1]; // save the str[0] to be the last char   
        str[len-1] = '\0'; // set the last char as null to reduce the length  
        str_reverse_rec(str+1); // recursion on str[1...len-2]   
        str[len-1] = tmp; // set the last char to be the original str[0] 
    }
}

int main() {
    char string[] = "string";
    str_reverse_rec(string);
    printf("%s \n", string);
}