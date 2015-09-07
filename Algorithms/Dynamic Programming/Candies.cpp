#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005],l[100005],r[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
    
    l[0] = r[N-1] = 1;
    for(int i=1;i<N;i++)
        if(a[i]>a[i-1])
            l[i] = l[i-1]+1;
        else    l[i] = 1;
    for(int i=N-2;i>=0;i--)
        if(a[i]>a[i+1])
            r[i] = r[i+1]+1;
        else    r[i] = 1;
    long long ans = 0;
    for(int i=0;i<N;i++)
        ans += max(l[i],r[i]);
    printf("%lld\n",ans);
    
    return 0;
}
