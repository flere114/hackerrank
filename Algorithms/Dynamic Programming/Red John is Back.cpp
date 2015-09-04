#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

long long dp[41][16];
long long a[41];
bool is[300000];

void pre(){
    memset(is,false,sizeof(is));
    is[0] = is[1] = true;
    for(int i=2;i<220000;i++){
        if(!is[i]){
            for(int j=i+i;j<220000;j+=i)
                is[j] = true;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    pre();
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    
    dp[1][1] = dp[2][3] = dp[3][7] = dp[4][15] = 1;
    dp[4][0] = 1;
    for(int i=5;i<=40;i++){
        for(int j=0;j<16;j++)
            dp[i][0] += dp[i-4][j];
        for(int j=1;j<16;j+=2){
            int jj = j>>1;
            dp[i][j] += (dp[i-1][jj] + dp[i-1][jj+8]);
        }
    }
    for(int i=1;i<41;i++)
        for(int j=0;j<16;j++)
            a[i] += dp[i][j];
    //printf("%lld\n",a[40]);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        int ans = 0;
        for(int i=2;i<=a[N];i++)
            if(!is[i])
                ans++;
        printf("%d\n",ans);
    }
    
    return 0;
}
