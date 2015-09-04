#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair<int,int> > v[102];
int d[102],in[102],t1[102],t2[102];
const int MAX = 1000000009;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N,M;t<T && scanf(" %d",&N)==1;t++){
        for(int i=1;i<=100;i++)
            in[i] = 0, d[i] = MAX, t1[i] = t2[i] = -1;
        for(int i=0,x,y;i<N && scanf(" %d %d",&x,&y)==2;i++)    t1[x] = y;
        scanf(" %d",&M);
        for(int i=0,x,y;i<M && scanf(" %d %d",&x,&y)==2;i++)    t2[x] = y;
        queue <int> q;
        q.push(1);
        d[1] = 0;
        while(!q.empty()){
            int x = q.front();  q.pop();
            in[x] = 0;
            for(int i=1;i<=6;i++){
                int nx = x+i;
                if(t1[nx]!=-1)  nx = t1[nx];
                if(t2[nx]!=-1)  nx = t2[nx];
                if(d[x] + 1 < d[nx]){
                    d[nx] = d[x]+1;
                    if(in[nx]==0){
                        in[nx] = 1;
                        q.push(nx);
                    }
                }
            }
        }
        if(d[100]==MAX)   d[100] = -1;
        printf("%d\n",d[100]);
    }
    
    return 0;
}
