#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,N;
    scanf(" %d",&T);
    
    for(int t=0;t<T && scanf(" %d",&N)==1;t++){
        int c = 0;
        for(int i=0;i<N && scanf(" %d",&a[i])==1;i++)
            if(a[i]>0)  c += a[i];
        int ans = -1000000009;
        if(c==0){
            for(int i=0;i<N;i++)
                ans = max(ans,a[i]);
            printf("%d %d\n",ans,ans);
            continue;
        }
        int now = 0, L = 0;
        for(int i=0;i<N;i++){
            now += a[i];
            ans = max(ans,now);
            while(now<0 && L<=i)
                now -= a[L], L++;
            if(L<i)
                ans = max(ans,now);
        }
        printf("%d %d\n",ans,c);
    }
    
    
    return 0;
}
