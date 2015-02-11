#include <stdio.h>

int getCycleLength(int n) {

    int CycleLength = 1;
    while(n != 1) {
        if(n%2==0) {
            n/=2;
        } else {
            n = 3*n + 1;
        }
        CycleLength++;
    }
    return CycleLength;
}

int main( int argc, char *argv[] ) {

    int i, j, n, max, currentCycleLength;

    while( scanf( "%d%d", &i, &j ) == 2 ) {
        int I=i, J=j;
        if ( I > J ) { 
            I=j; J=i; 
        }

        max = -1; // Maximum cycle length between [i,j]
        for(n = I; n <= J; n++) {
            currentCycleLength = getCycleLength(n);
            if(currentCycleLength > max) {
                max = currentCycleLength;
            }
        }
        printf("%d %d %d\n", i, j, max);
    }
    return 0;    

}


