/****************************************************************************
 * crc-simple-1.c
 *      This program computes the crc of a value entered with a key entered.
 *      The key is the 'polynomial' in binary form and the data is the binary
 *      data that will have its crc value computed.
 * 
 *      The program completes all of its operations with char values. The
 *      binary data entered is stored in ASCII char values.
 ***************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    int i, j, keylen, msglen;
    char input[100], key[30], temp[30], quot[100], rem[30], key1[30];

    /**************************************
     * Collect User Input
     * ***********************************/
    printf("Enter Data: ");
    gets(input);
    printf("Enter Key: ");
    gets(key);
    keylen = strlen(key);
    msglen = strlen(input);
    // Copy key to key1
    strcpy(key1, key);

    /**************************************
     *  Calculate the CRC
     *************************************/
    // Append key width (aka keylen - 1) number of 0's to end of message
    for (i = 0; i < keylen - 1; i++)
    {
        input[msglen + i] = '0';
    }

    // Copy keylen of input to temp array
    for (i = 0; i < keylen; i++)
        temp[i] = input[i];

    // For every bit in the message...
    for (i = 0; i < msglen; i++)
    {
        // Copy the MSB of the temp input to quot[i]...
        quot[i] = temp[0];

        // This section determines if the MSB is 1 or 0 and turns the key 'ON' or 'OFF' accordingly.
        ///////////////////////////////////////////////////////////
        // If it equals 0...
        if (quot[i] == '0')
            // Set all bits of the key to 0.
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        // If it does not equal 0 (it equals 1)
        else
            // Set the key equal to the real key.
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];

        // This section is equivalent to a XOR of the bits (temp XOR key)
        ///////////////////////////////////////////////////////////    
        // For every bit in the key length minus 1 (aka width)
        for (j = keylen - 1; j > 0; j--)
        {
            // If the bit in the temp array equals the bit in the key array...
            if (temp[j] == key[j])
                // The remainder is 0
                rem[j - 1] = '0';
            else
                // The remainder is 1
                rem[j - 1] = '1';
        }
                                                                //   100000111        100000111
        // "Drop a zero down" from the augMsg into the remainder --> 10100100 becomes 101001000
        rem[keylen - 1] = input[i + keylen];

        // Copy rem char array to temp char array.
        strcpy(temp, rem);
    }
    // Copy temp char array to rem char array.
    strcpy(rem, temp);

    // Display output
    printf("\nQuotient is ");
    for (i = 0; i < msglen; i++)
        printf("%c", quot[i]);
    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++)
        printf("%c", input[i]);
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    getch();
}