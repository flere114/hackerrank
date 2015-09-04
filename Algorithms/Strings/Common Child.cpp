#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[6000],s2[6000];
int dp[5005][5005];

int LCS(){
    int len1 = strlen(s1), len2 = strlen(s2);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }else{
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf(" %s %s",s1,s2);
    printf("%d\n",LCS());
    
    return 0;
}
