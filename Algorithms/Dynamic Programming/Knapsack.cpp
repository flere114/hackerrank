#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int dp[2005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N,K;t<T && scanf(" %d %d",&N,&K)==2;t++){
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i=0,x;i<N && scanf(" %d",&x)==1;i++)
            for(int j=x;j<=K;j++)
                if(dp[j-x]==1)  dp[j] = 1;
        int ans = K;
        for(;ans>=0 && dp[ans]==0;ans--);
        printf("%d\n",ans);
    }
    
    return 0;
}
