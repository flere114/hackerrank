#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        int mini = 1000;
        for(int i=0;i<N && scanf(" %d",&a[i])==1;i++)
            mini = min(mini,a[i]);
        int ans = 1000000009;
        for(int i=0;i<=mini;i++){
            int tmp = 0;
            for(int j=0;j<N;j++){
                int left = a[j] - i;
                tmp += left/5;
                left %= 5;
                tmp += left/2;
                left %= 2;
                tmp += left;
            }
            ans = min(ans,tmp);
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
