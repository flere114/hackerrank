/*
 Key idea : for every node, recode its 1,2,4,8,...,2^i ancestor
 So the space complexity is O(NlogN)
 And the time complexity for each query can be bound in O(NlogN)
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

int par[100005],d[100005];
vector <int> v[100005],a[100005];

void build(int x){
    int now = par[x], c = 0;
    a[x].push_back(x);
    while(now!=0){
        a[x].push_back(now);
        c++;
        if(a[now].size()<=c) break;
        now = a[now][c];
    }
}
void dfs(int x){
    for(int i=0;i<v[x].size();i++){
        d[v[x][i]] = d[x]+1;
        build(v[x][i]);
        dfs(v[x][i]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<100005;i++)
            par[i] = -1, d[i] = 0, v[i].clear(), a[i].clear();
        for(int i=0,x,y;i<N && scanf(" %d %d",&x,&y)==2;i++)
            par[x] = y, v[y].push_back(x);
        d[v[0][0]] = 1;
        dfs(v[0][0]);
        int Q;
        scanf(" %d",&Q);
        for(int q=0,md,x,y,k;q<Q && scanf(" %d",&md)==1;q++){
            if(md==0){
                scanf(" %d %d",&x,&y);
                par[y] = x;
                d[y] = d[x]+1;
                build(y);
            }else if(md==1){
                scanf(" %d",&x);
                par[x] = -1;
                a[x].clear();
            }else{
                scanf(" %d %d",&x,&k);
                int lv,ans = 0, now = x;
                if(par[x]==0 || k>=d[x] || par[x]==-1){
                    printf("0\n");
                    continue;
                }
                while(k>=0){
                    if(k==0){
                        ans = now;
                        break;
                    }else if(k==1){
                        ans = a[now][1];
                        break;
                    }
                    for(lv=1;;lv++)
                        if((1<<lv) > k)
                            break;
                    // now, (1<<(lv-1)) <= k, ans should be in [lv]
                    lv = min(lv,int(a[now].size())-1);
                    k -= (1<<(lv-1));
                    now = a[now][lv];
                }
                printf("%d\n",ans);
            }
        }
    }
    
    
    return 0;
}
