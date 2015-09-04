#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char s[55][55];
int d[130][55][55], in[130][55][55];
int op[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char ok[4] = {'U','D','L','R'};
const int MAX = 1000000009;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,K,edx,edy;
    scanf(" %d %d %d",&N,&M,&K);
    for(int i=0;i<N;i++)
        scanf(" %s",s[i]);
    
    for(int i=0;i<130;i++)
        for(int j=0;j<55;j++)
            for(int k=0;k<55;k++)
                d[i][j][k] = MAX, in[i][j][k] = 0;
    
    d[0][0][0] = 0;
    queue <int> q;
    q.push(0);
    q.push(0);
    q.push(0);
    while(!q.empty()){
        int z = q.front();  q.pop();
        int x = q.front();  q.pop();
        int y = q.front();  q.pop();
        in[z][x][y] = 0;
        if(s[x][y]=='*'){
            edx = x, edy = y;
            continue;
        }
        for(int i=0;i<4;i++){
            int nx = x+op[i][0], ny = y+op[i][1];
            if(nx<0 || ny<0 || nx>=N || ny>=M)  continue;
            int cost = s[x][y]==ok[i] ? 0 : 1;
            int nz = z+cost;
            if(nz>111)  continue;
            if(d[z][x][y] + 1 < d[nz][nx][ny]){
                d[nz][nx][ny] = d[z][x][y] + 1;
                if(in[nz][nx][ny]==0){
                    in[nz][nx][ny] = 1;
                    q.push(nz);
                    q.push(nx);
                    q.push(ny);
                }
            }
        }
    }
    int ans = 0;
    for(;ans<111;ans++)
        if(d[ans][edx][edy]<=K)
            break;
    if(ans==111)    ans = -1;
    printf("%d\n",ans);
    
    return 0;
}
