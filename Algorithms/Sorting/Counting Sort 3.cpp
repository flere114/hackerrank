#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[20];
int c[100];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int N;
    scanf(" %d",&N);
    memset(c,0,sizeof(c));
    for(int i=0,x;i<N && scanf(" %d %s",&x,s)==2;i++)
        c[x]++;
    for(int i=1;i<100;i++)
        c[i] += c[i-1];
    
    for(int i=0;i<100;i++)
        printf("%d ",c[i]);
    
    return 0;
}
