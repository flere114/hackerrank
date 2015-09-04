#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int d[402][402];
const int MAX = 1000000009;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    scanf(" %d %d",&N,&M);
    
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(i==j)    d[i][j] = 0;
            else    d[i][j] = MAX;
    for(int i=0,x,y,z;i<M && scanf(" %d %d %d",&x,&y,&z)==3;i++)
        d[x][y] = z;
    
    for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    int Q;
    scanf(" %d",&Q);
    for(int i=0,x,y;i<Q && scanf(" %d %d",&x,&y)==2;i++)
        if(d[x][y]==MAX)    printf("-1\n");
        else    printf("%d\n",d[x][y]);
    
    return 0;
}
