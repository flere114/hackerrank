#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    
    for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
    sort(a,a+N);
    int diff = 1000000009;
    for(int i=1;i<N;i++)
        diff = min(diff,a[i]-a[i-1]);
    for(int i=1;i<N;i++)
        if(a[i]-a[i-1] == diff)
            printf("%d %d ",a[i-1],a[i]);
    
    return 0;
}
