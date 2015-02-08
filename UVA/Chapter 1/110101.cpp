#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getCycleLength(int n) {

    int CycleLength = 1;
    while(n != 1) {
        if(n%2==0) {
            n/=2;
        } else {
            n = (n * 3) + 1;
        }
        CycleLength++;
    }
    return CycleLength;
}

int main() {
    unsigned int i, j, n, max, currentCycleLength;

    while(cin>>i>>j) {
        max = 0; // Maximum cycle length between [i,j]
        for(n = i; n <= j; n++) {
            currentCycleLength = getCycleLength(n);
            if(currentCycleLength > max) {
                max = currentCycleLength;
            }
        }
        printf("%u %u %u\n", i,j,max);
    }
    return 0;
}


