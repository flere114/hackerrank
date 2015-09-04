#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> v[102];
int c[102];

void dfs(int x,int pa){
    for(int i=0;i<int(v[x].size());i++){
        int y = v[x][i];
        if(y==pa)   continue;
        dfs(y,x);
        c[x] += c[y];
    }
    c[x]++;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    scanf(" %d %d",&N,&M);
    
    for(int i=0;i<=N;i++)
        v[i].clear(), c[i] = 0;
    for(int i=0,x,y;i<M && scanf(" %d %d",&x,&y)==2;i++)
        v[x].push_back(y), v[y].push_back(x);
    dfs(1,-1);
    int ans = 0;
    for(int i=1;i<=N;i++)
        if(c[i]%2 == 0)
            ans++;
    printf("%d\n",ans-1);
    
    return 0;
}
