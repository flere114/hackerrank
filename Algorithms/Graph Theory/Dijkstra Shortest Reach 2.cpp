#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector <pair<int,int> > v[3003];
const int MAX = 1000000009;
int d[3003],in[3003];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N,M;t<T && scanf(" %d %d",&N,&M)==2;t++){
        for(int i=1;i<=N;i++)
            v[i].clear(), d[i] = MAX, in[i] = 0;
        for(int i=0,x,y,z;i<M && scanf(" %d %d %d",&x,&y,&z)==3;i++)
            v[x].push_back(make_pair(y,z)), v[y].push_back(make_pair(x,z));
        int st;
        scanf(" %d",&st);
        
        queue <int> q;
        q.push(st);
        d[st] = 0;
        while(!q.empty()){
            int x = q.front();  q.pop();
            in[x] = 0;
            for(int i=0;i<v[x].size();i++){
                int nx = v[x][i].first, dis = v[x][i].second;
                if(d[x] + dis < d[nx]){
                    d[nx] = d[x] + dis;
                    if(in[nx]==0){
                        in[nx] = 1;
                        q.push(nx);
                    }
                }
            }
        }
        int re = 0;
        for(int i=1;i<=N;i++){
            if(i==st)   continue;
            if(re==1)   printf(" ");
            re = 1;
            if(d[i]==MAX)   printf("-1");
            else    printf("%d",d[i]);
        }
        printf("\n");
    }
    
    return 0;
}
