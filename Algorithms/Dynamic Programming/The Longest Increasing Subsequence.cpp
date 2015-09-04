#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005],up[1000005],pos[1000005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
    up[0] = a[0];
    pos[0]=0;
    int m = 1;
    for(int i=1;i<N;i++){
        int t = lower_bound(up,up+m,a[i])-up;
        up[t] = a[i];
        pos[i]=t;
        m = t+1>m?t+1:m;
    }
    printf("%d\n",m);
    
    return 0;
}
