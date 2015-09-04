#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int ans[10000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    scanf(" %d",&N);
    memset(ans,0,sizeof(ans));
    ans[0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<10000;j++)
            ans[j] *= i;
        for(int j=0,add=0;j<10000;j++){
            ans[j] += add;
            add = ans[j]/10;
            ans[j] %= 10;
        }
    }
    for(int i=9999,re=0;i>=0;i--){
        if(ans[i]==0 && re==0)  continue;
        else{
            printf("%d",ans[i]);
            re = 1;
        }
    }
    printf("\n");
    
    return 0;
}
