#include <stdio.h>

typedef char uint8_t;
typedef uint8_t crc;

#define POLYNOMIAL 0x07 /* 1 0000 0111 */
#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))

crc crcTable[256];

crc crcNaive(uint8_t const message)
{
    uint8_t  remainder;	
    
    //Initially, the dividend is the remainder.
    remainder = message;

    // For each bit position in the message....
    for (uint8_t bit = 8; bit > 0; --bit)
    {
        // If the uppermost bit is a 1...
        if (remainder & 0x80)
        {
            // XOR the previous remainder with the divisor.
            remainder ^= POLYNOMIAL;
        }

        // Shift the next bit of the message into the remainder.
        remainder = (remainder << 1);
    }

    // Return only the relevant bits of the remainder as CRC.
    return (remainder >> 4);

}   /* crcNaive() */


void crcInit() {

}

crc computeCrc(char message[]) {
    
    getchar();
    return 0;
}

int main() {
    printf("%d", crcNaive(0x52));
    
    getchar();
    return 0;
}