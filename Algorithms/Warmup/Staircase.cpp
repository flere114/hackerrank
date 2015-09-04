#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    for(int i=0;i<N;i++,printf("\n"))
        for(int j=0,k=N-i-1;j<N;j++)
            if(j<k) printf(" ");
            else    printf("#");
    return 0;
}
