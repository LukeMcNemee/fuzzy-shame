#include <stdio.h>
#include <stdbool.h>

/**
* Implementation of Ascii85 alghoritm
* Accepts up to 40 characters on input and returns these characters coded in Ascii85
* @author Lukáš Němec
* @version 3
*/


/**
* This method transforms unsigned long to 5 unsogned ints, which represent characters
* This is done by divison by 85 as specified in Ascii85 alghoritm
*
* @param number Unsigned long, which is transformed to 5 characters
* @param output Pointer to array, where are stored output characters
* @param pos Position shift on output acording to previous procession by groups of four
*/
void
longToChar (unsigned long number, unsigned int* output, int pos)
{
    int index;
    for (int i = 0; i < 5; i++){
        output[pos + 5 - i] = (number % 85) + 33;
        number = number / 85;
    }

}

int
main (void)
{
    unsigned int input[39];
    int x = getchar();
    gets(intput);
    int i = 0;

    //reading characters from input
    while (x != 10 && x != EOF && i < 40) {
        input[i] = x;
        x = getchar();        
        i++;
    }

    //addition of /0 characters so input is divisible by 4.
    while ( i % 4 != 0 ) {
        input[i] = 0;
        i++;
    }

    unsigned int output[(i / 4) * 5];

    //input characters are processed in groups of four
    //each group is by shift transformed to long and then back to char by method longToChar
    for (int j = 0; j < (i / 4); j++ ) {
        long sum = 0;
        sum += input[0 + j * 4] << 24;
        sum += input[1 + j * 4] << 16;
        sum += input[2 + j * 4] << 8;
        sum += input[3 + j * 4];

        longToChar( sum, output, (j * 5));
    }

    //printing output characters to output
    for (int j = 1; j <= (i / 4) * 5; j++) {
        putchar(output[j]);
    }
    printf("\n");

    return 0;
}

