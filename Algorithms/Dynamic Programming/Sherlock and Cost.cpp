#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[100005][2],a[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
        memset(dp,-1,sizeof(dp));
        dp[0][0] = dp[0][1] = 0;
        for(int i=1;i<N;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+abs(a[i-1]-1));
            dp[i][1] = max(dp[i-1][0]+abs(a[i]-1),dp[i-1][1]+abs(a[i-1]-a[i]));
        }
        printf("%d\n",max(dp[N-1][0],dp[N-1][1]));
    }
    
    return 0;
}
