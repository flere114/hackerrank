/*
 Key idea : Monte Carlo method
 
 Get AC.. haha
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <time.h>
using namespace std;

char s[1003][1003],p[1003][1003];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    srand(time(NULL));
    int T;
    scanf(" %d",&T);
    for(int t=0,N,M,R,C;t<T && scanf(" %d %d",&N,&M)==2;t++){
        for(int i=0;i<N;i++)
            scanf(" %s",s[i]);
        scanf(" %d %d",&R,&C);
        for(int i=0;i<R;i++)
            scanf(" %s",p[i]);
        int ans = 0;
        for(int i=0;i+R-1<N && ans==0;i++){
            for(int j=0;j+C-1<M && ans==0;j++){
                if(s[i][j]==p[0][0]){
                    int nt = 10000, ok = 1;
                    for(int k=0;k<nt && ok==1;k++){
                        int r = rand()%R, c = rand()%C;
                        if(s[i+r][j+c]!=p[r][c])
                            ok = 0;
                    }
                    if(ok==1)   ans = 1;
                }
            }
        }
        if(ans==0)  printf("NO\n");
        else    printf("YES\n");
    }
    
    return 0;
}
