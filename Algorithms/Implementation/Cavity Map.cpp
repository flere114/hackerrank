#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char s[102][102],ans[102][102];
int op[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    for(int i=0;i<N;strcpy(ans[i],s[i]),i++)
        scanf(" %s",s[i]);
    
    for(int i=1;i<N-1;i++){
        for(int j=1;j<N-1;j++){
            int ok = 1;
            for(int k=0;k<4;k++){
                int ni = i + op[k][0], nj = j + op[k][1];
                if(s[i][j] <= s[ni][nj])
                    ok = 0;
            }
            if(ok==1)   ans[i][j] = 'X';
        }
    }
    for(int i=0;i<N;i++)
        printf("%s\n",ans[i]);
    
    return 0;
}
