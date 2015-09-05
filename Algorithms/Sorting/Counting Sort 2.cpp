#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int c[100];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;
    scanf(" %d",&N);
    memset(c,0,sizeof(c));
    for(int i=0,x;i<N && scanf(" %d",&x)==1;i++)
        c[x]++;
    for(int i=0;i<100;i++)
        if(c[i]>0)
            for(int j=0;j<c[i];j++)
                printf("%d ",i);
    
    return 0;
}
