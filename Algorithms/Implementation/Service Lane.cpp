#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int pre[3][100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,Q;
    scanf(" %d %d",&N,&Q);
    memset(pre,0,sizeof(pre));
    
    for(int i=1,x;i<=N && scanf(" %d",&x)==1;i++)
        pre[x-1][i] = 1;
    for(int i=0;i<3;i++)
        for(int j=1;j<=N;j++)
            pre[i][j] += pre[i][j-1];
    for(int i=0,x,y;i<Q && scanf(" %d %d",&x,&y)==2;i++){
        y++;
        for(int j=0;j<3;j++)
            if(pre[j][y]-pre[j][x] > 0){
                printf("%d\n",j+1);
                break;
            }
    }
    
    return 0;
}
