#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,K,Q;
    scanf(" %d %d %d",&N,&K,&Q);
    for(int i=0;i<N && scanf(" %d",&a[(i+K)%N])==1;i++);
    
    for(int i=0,x;i<Q && scanf(" %d",&x)==1;i++)
        printf("%d\n",a[x]);
    
    return 0;
}
