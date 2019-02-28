#include <stdio.h>
typedef unsigned char byte;

int crc_tbl [255] = {
    0x000000
};

/**************************************************
 * showbits(unsinged int x)
 *  Method to show 32 bits of a number on the 
 *  console.
 * 
 */

void showbits(unsigned int x) {
    for(int i = (sizeof(int) * 8) - 1; i >= 0; i--) {
       (x & (1u << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

// int main() {
//     int j = 5225;
//     printf("%d in binary \t\t ", j);
//     /* assume we have a function that prints a binary string when given 
//        a decimal integer 
//      */
//     showbits(j);

//     /* the loop for right shift operation */
//     for (int m = 0; m <= 5; m++) {
//         int n = j >> m;
//         printf("%d right shift %d gives ", j, m);
//         showbits(n);
//     }
//     return 0;
// }

/***************************************************
 * 
 *  https://barrgroup.com/Embedded-Systems/How-To/CRC-Calculation-C-Code
 *  Simple bitwise CRC-8 implementation 
 *
 ***************************************************/
#define POLYNOMIAL 0b100000111  /* 0x07 */

typedef unsigned char uint8_t;
crcNaive(uint8_t const message)
{
    uint8_t  remainder;	

    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;

    /*
     * For each bit position in the message....
     */
    for (uint8_t bit = 8; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & 0x80)
        {
            /*
             * XOR the previous remainder with the divisor.
             */
            remainder ^= POLYNOMIAL;
        }

        /*
         * Shift the next bit of the message into the remainder.
         */
        remainder = (remainder << 1);
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return (remainder >> 4);

}   /* crcNaive() */

int main() {

    /*****************************
     *  Test table based byte algorithm 
     *  for CRC from "A Painless Guide to CRC"
     * 
     */

    // int next_aug_msg_byte = 0x0; // next byte of the augementedmessage
    // int r = 0x52; // 32-bit crc register

    // // Original Regiser Value
    // printf("Register: \t\t%d\n", r);
    // showbits(r);

    // char t = (r >> 24) & 0x00FF;
    // printf("Top Byte: \t\t%d\n", t);
    // showbits(t);

    // // Register = Register << 24 | next_aug_msg_byte
    // r = (r << 24) | next_aug_msg_byte;
    // printf("Register Step 2: \t%d\n", r);
    // showbits(r);

    // // Register = Register XOR precomputer_table[Top]
    // r = r ^ crc_tbl[t];

    // getchar();

    /******************************
     *  Test crcNaive()
     * 
     */

    showbits(crcNaive(0x52));

    getchar();
    return 0;
}