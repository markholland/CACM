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
    int i, j, n, max, currentCycleLength;

    #ifndef ONLINE_JUDGE 
    ofstream fout ("110101.oup");
    ifstream fin ("110101.inp");
    #endif

    #ifdef ONLINE_JUDGE
    while(cin>>i>>j) {
    #else
    while(fin>>i>>j) {
    #endif
        max = 0; // Maximum cycle length between [i,j]
        for(n = i; n <= j; n++) {
            currentCycleLength = getCycleLength(n);
            if(currentCycleLength > max) {
                max = currentCycleLength;
            }
        }

        #ifdef ONLINE_JUDGE
        cout << i << " " << j << " " << max << endl;
        #else
        fout << i << " " << j << " " << max << endl;
        #endif
    }
    return 0;
}


