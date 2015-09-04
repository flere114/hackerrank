#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,v,ans;
    scanf(" %d %d",&v,&N);
    for(int i=0,x;i<N && scanf(" %d",&x)==1;i++)
        if(x==v)
            ans = i;
    printf("%d\n",ans);
    
    return 0;
}
