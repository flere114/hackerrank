/*
 Key idea : brute force search with some optimization
 
 Because N = 20, so we can enumerate all the subsets (2^20)
 But we need to calculate the connected component efficiently, otherwise the time complexity may be O(N*N*2^N)
 I solve it in O(N* 2^N)
 
 The idea is that I will maintain an array a, that record all the connected component, so (a[i] & a[j]) must be 0 when i!=j
 Then when adding a new element d[lv] in it, I merge all a[i] that has at least one bit '1' at the same position with d[lv].
 
 Finally, at the end of the recursive, the ans can plus the size of a, which mean the number of connected component(size>1). And plus those bits are zero.
 
 But we should take care, if our array a contains element 0, then the answer should minus 1. Think abount it, or check this test case : 1 0. The answer should be 128.
 
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N,ans;
unsigned long long d[22];

void dfs(int lv,int c,unsigned long long *a){
    if(lv==N){
        ans += c;
        for(int i=0;i<c;i++)
            if(a[i]==0)
                ans--;
        unsigned long long m = 0;
        for(int i=0;i<c;i++)
            m |= a[i];
        for(int i=0;i<64;i++)
            if((((unsigned long long)1 << i) & m)==0)
                ans++;
        return;
    }
    dfs(lv+1,c,a);
    unsigned long long m = d[lv], b[22];
    int nc = 0;
    for(int i=0;i<c;i++)
        if((m & a[i])!=0)
            m |= a[i];
        else    b[nc++] = a[i];
    b[nc++] = m;
    dfs(lv+1,nc,b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> N;
    for(int i=0;i<N && cin >> d[i];i++);
    
    unsigned long long a[22],b[22];
    ans = 0;
    dfs(0,0,a);
    
    printf("%d\n",ans);
    
    return 0;
}
