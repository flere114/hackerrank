#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long dp[100005][2];  // 0 for max, 1 for min
long long a[100005];
int N;
const long long MAX = (long long)10000000000000000;

long long rec(int x,int lv){
    if(x>=N)    return 0;
    if(lv%2==0){
        if(dp[x][0]!=-1)    return dp[x][0];
        long long ret = 0;
        ret = max(ret,a[x]+rec(x+1,lv+1));
        if(x+1<N)   ret = max(ret,a[x]+a[x+1]+rec(x+2,lv+1));
        if(x+2<N)   ret = max(ret,a[x]+a[x+1]+a[x+2]+rec(x+3,lv+1));
        return dp[x][0] = ret;
    }else{
        if(dp[x][1]!=MAX)    return dp[x][1];
        long long ret = MAX;
        ret = min(ret,rec(x+1,lv+1));
        if(x+1<N)   ret = min(ret,rec(x+2,lv+1));
        if(x+2<N)   ret = min(ret,rec(x+3,lv+1));
        return dp[x][1] = ret;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<N && scanf(" %lld",&a[i])==1;i++)
            dp[i][0] = -1, dp[i][1] = MAX;
        cout << rec(0,0) << endl;
    }
    
    return 0;
}
