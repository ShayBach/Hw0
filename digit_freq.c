// 316147016
#include <stdio.h> //printf,scanf
#include <string.h> //strlen,strcat,etc 
#include <math.h>  //sqrt,pow,floor,ceil,etc
#include <stdlib.h> //malloc, free

#define NUM_OF_DIGITS 10
#define MAX_STRING_INPUT 1000 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char str[MAX_STRING_INPUT] = {0};
    int i=0;
    int digit_cnt[NUM_OF_DIGITS] = {0}; //10 integer array initialized to 0
    enum {ASCII_ZERO = 48, ASCII_NINE = 57};
    scanf("%s",str);
    // Count occurrences of each digit in the string
    while (str[i] != '\0' && i < MAX_STRING_INPUT) {
        // Check if the character is a digit (ASCII '0' to '9')
       if (((int)str[i] >= ASCII_ZERO) && ((int)str[i] <= ASCII_NINE)) {
            digit_cnt[(int)str[i] - ASCII_ZERO]++;
       }
       i++;
    }
     // Print the counts of each digit
    for (i=0; i<NUM_OF_DIGITS; i++) {
        printf("%d%s", digit_cnt[i], i < 9 ? " " : "");
    }
    printf("\n");
}
