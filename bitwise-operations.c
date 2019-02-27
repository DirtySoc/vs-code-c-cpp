#include <stdio.h>
    
void showbits(unsigned int x) {
    for(int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       (x & (1u << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

int main() {
    int j = 5225;
    printf("%d in binary \t\t ", j);
    /* assume we have a function that prints a binary string when given 
       a decimal integer 
     */
    showbits(j);

    /* the loop for right shift operation */
    for (int m = 0; m <= 5; m++) {
        int n = j >> m;
        printf("%d right shift %d gives ", j, m);
        showbits(n);
    }
    return 0;
}