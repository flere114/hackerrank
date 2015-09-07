#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1003];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
    sort(a,a+N);
    a[N++] = 1300;
    
    for(int i=0;i<N-1;){
        int len = a[i];
        printf("%d\n",N-i-1);
        for(i=i+1;i<N;i++)
            if(a[i]!=len)
                break;
    }
    
    return 0;
}
