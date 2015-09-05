#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int T;
    scanf(" %d",&T);
    
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        for(int i=0;i<N && scanf(" %d",&a[i])==1;i++);
        sort(a,a+N);
        long long ans = 0;
        for(int i=0;i<N;){
            int c = 1,j;
            for(j=i+1;j<N;j++)
                if(a[i]==a[j])
                    c++;
                else break;
            i = j;
            if(c>1)  ans += (long long)c*(c-1);
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}
