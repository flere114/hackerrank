#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct A{
    int v,p;
}AA;
int ini[50004],use[50004];
AA a[50004];

bool cmp(AA c,AA d){
    if(c.v!=d.v)    return c.v > d.v;
    return c.p < d.p;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<N && scanf(" %d",&ini[i])==1;i++)
            use[i] = 0, a[i].v = ini[i], a[i].p = i;
        sort(a,a+N,cmp);
        long long ans = 0;
        for(int i=0;i<N;i++){
            if(use[a[i].p]==0){
                use[a[i].p] = 1;
                for(int j=a[i].p-1;j>=0 && use[j]==0;j--)
                    use[j] = 1, ans += (a[i].v-ini[j]);
            }
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}
