#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[102][102];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        int ok = 1;
        for(int n=0;n<N;n++){
            scanf(" %s",s[n]);
            sort(s[n],s[n]+N);
        }
        for(int j=0;j<N && ok==1;j++)
            for(int i=1;i<N;i++)
                if(s[i][j] < s[i-1][j])
                    ok = 0;
        if(ok==0)   printf("NO\n");
        else printf("YES\n");
    }
    
    return 0;
}
