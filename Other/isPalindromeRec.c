#include <stdbool.h> 
#include <stdio.h> 
#include <string.h>

bool is_palindrome(char* str) {
    int len = strlen(str);
    // base case
    if (len <= 1) { 
        return true;
    }
    // palindrome is if str[0] == str[len - 1]
    if (str[0] == str[len - 1]) {
        // reduce length by one by adding NULL terminator 
        str[len - 1] = '\0';
        return is_palindrome(str + 1); //  look at str[1] ... str[len - 2]
    }
    
    return false;
}

int main() {
    char string[] = "racecar";
    int x = is_palindrome(string);
    printf("%d \n", x);
    return 0;
}