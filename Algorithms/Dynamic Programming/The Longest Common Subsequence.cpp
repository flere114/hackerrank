#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int dp[102][102],pre[102][102],N,M,a[102],b[102];
int op[4][2] = {{-1,-1},{-1,0},{0,-1},{-1,-1}};
vector <int> ans;

void LCS(){
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(a[i]==b[j]){
                if(dp[i-1][j-1]+1 > dp[i][j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    pre[i][j] = 0;
                }
            }else{
                if(dp[i-1][j] > dp[i][j]){
                    dp[i][j] = dp[i-1][j];
                    pre[i][j] = 1;
                }
                if(dp[i][j-1] > dp[i][j]){
                    dp[i][j] = dp[i][j-1];
                    pre[i][j] = 2;
                }
                if(dp[i-1][j-1] > dp[i][j]){
                    dp[i][j] = dp[i-1][j-1];
                    pre[i][j] = 3;
                }
            }
        }
    }
}
void rec(int x,int y){
    if(pre[x][y]==-1){
        return;
    }
    int nx = x+op[pre[x][y]][0], ny = y+op[pre[x][y]][1];
    rec(nx,ny);
    if(pre[x][y]==0)    ans.push_back(a[x]);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    scanf(" %d %d",&N,&M);
    for(int i=1;i<=N && scanf(" %d",&a[i])==1;i++);
    for(int i=1;i<=M && scanf(" %d",&b[i])==1;i++);
    
    ans.clear();
    LCS();
    rec(N,M);
    //printf("%d\n",dp[N][M]);
    for(int i=0;i<ans.size();i++)
        if(i==0)    printf("%d",ans[i]);
        else    printf(" %d",ans[i]);
    printf("\n");
    
    return 0;
}
