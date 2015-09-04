#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> v[1003];
const int MAX = 1000000009;
int in[1003],d[1003];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N,M;t<T && scanf(" %d %d",&N,&M)==2;t++){
        for(int i=1;i<=N;i++)
            v[i].clear(), in[i] = 0, d[i] = MAX;
        for(int i=0,x,y;i<M && scanf(" %d %d",&x,&y)==2;i++)
            v[x].push_back(y), v[y].push_back(x);
        int st;
        scanf(" %d",&st);
        d[st] = 0;
        queue <int> q;
        q.push(st);
        
        while(!q.empty()){
            int x = q.front();  q.pop();
            in[x] = 0;
            for(int i=0;i<v[x].size();i++){
                int nx = v[x][i];
                if(d[x] + 6 < d[nx]){
                    d[nx] = d[x] + 6;
                    if(in[nx]==0){
                        in[nx] = 1;
                        q.push(nx);
                    }
                }
            }
        }
        int re = 0;
        for(int i=1;i<=N;i++){
            if(i!=st){
                if(re==1)  printf(" ");
                re = 1;
                if(d[i]==MAX) printf("-1");
                else    printf("%d",d[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
