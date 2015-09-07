/*
 Key idea : prefix sum and sweep line
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[505][505];
int u[505][505],l[505][505];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    scanf(" %d %d",&N,&M);
    
    for(int i=0;i<N;i++)
        scanf(" %s",s[i]);
    memset(u,0,sizeof(u));
    memset(l,0,sizeof(l));
    
    for(int i=0;i<N;i++)
        for(int j=1;j<M;j++)
            if(s[i][j-1]!='x')
                l[i][j] = l[i][j-1]+1;
    for(int i=1;i<N;i++)
        for(int j=0;j<M;j++)
            if(s[i-1][j]!='x')
                u[i][j] = u[i-1][j]+1;
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int L,vgap = j-i,hgap;
            for(L=0;L<M;L++)
                if(s[i][L]!='x' && s[j][L]!='x' && u[j][L]>=vgap)
                    break;
            for(int R=L+1;R<M;R++){
                hgap = R-L;
                if(s[i][R]!='x' && s[j][R]!='x' && u[j][R]>=vgap)
                    ans = max(ans,(hgap+vgap)*2);
                if(s[i][R]=='x' || s[j][R]=='x'){
                    L = R+1;
                    for(;L<M;L++)
                        if(s[i][L]!='x' && s[j][L]!='x' && u[j][L]>=vgap)
                            break;
                    R = L;
                }
            }
        }
    }
    if(ans==0)  printf("impossible\n");
    else    printf("%d\n",ans);
    
    return 0;
}
