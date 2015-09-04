#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long dp[255];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    scanf(" %d %d",&N,&M);
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int m=0,x;m<M && scanf(" %d",&x)==1;m++){
        for(int i=x;i<=N;i++)
            dp[i] += dp[i-x];
    }
    printf("%lld\n",dp[N]);
    
    return 0;
}
