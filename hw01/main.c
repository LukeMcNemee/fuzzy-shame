#include <stdio.h>
#include <stdbool.h>


void
longToChar (unsigned long number, int* output, int pos){
    for (int i = 0; i < 5; i++){
        output[pos + 5 - i] = (number % 85)+33;
        number = number / 85;

    }

}


long getBytes(int x, int p, int n){
    return (x >> (p+1-n)) & ~(~0 << n);
}

int
main (void)
{
    int input[39];
    int x = getchar();
    int i = 0;
    while (x != 10 && x != 04 && i < 40){
        input[i] = x;
        x = getchar();        
        i++;
    }

    while ( (i) % 4 != 0 ) {
        input[i]= 0;
        i++;
    }

    int output[(i / 4) * 5];

    for (int j = 0; j < i/4; j++){
        long sum = 0;
        sum += input[0 + j * 4] << 24;
        sum += input[1 + j * 4] << 16;
        sum += input[2 + j * 4] << 8;
        sum += input[3 + j * 4];

        longToChar( sum, output, (j * 5));
    }

    for (int j = 0; j <= (i / 4) * 5; j++){
        putchar(output[j]);
    }
    putchar(10);

    return 0;
}

