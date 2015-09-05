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
        if(i==0)    printf("%d",c[0]);
        else    printf(" %d",c[i]);
    printf("\n");
    
    return 0;
}
