#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[505][505];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M,c=0,maxi = 0;
    scanf(" %d %d",&N,&M);
    for(int i=0;i<N;i++)
        scanf(" %s",s[i]);
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int t = 0;
            for(int k=0;k<M;k++)
                if(s[i][k]=='1' || s[j][k]=='1')
                    t++;
            if(t>maxi)  maxi = t, c = 1;
            else if(t==maxi)    c++;
        }
    }
    printf("%d\n%d\n",maxi,c);
    
    return 0;
}
