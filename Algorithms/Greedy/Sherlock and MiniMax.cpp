/*
 My solution is not good....I think.
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[102];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,P,Q;
    cin >> N;
    for(int i=0;i<N && cin >> a[i];i++);
    cin >> P >> Q;
    sort(a,a+N);
    
    if(Q<=a[0]){
        printf("%d\n",P);
        return 0;
    }else if(P>=a[N-1]){
        printf("%d\n",Q);
        return 0;
    }else{
        int ans = 0, diff = 0;
        if(P<a[0]){
            int gap = a[0]-P;
            if(gap>diff)    diff = gap, ans = P;
        }
        if(Q>a[N-1]){
            int gap = Q-a[N-1];
            if(gap>diff)    diff = gap, ans = Q;
            else if(gap==diff)  ans = min(ans,Q);
        }
        for(int i=0;i<N-1;i++){
            if(a[i]+1 == a[i+1])    continue;
            if(a[i]>=P && a[i+1]<=Q){
                int mid = (a[i]+a[i+1])/2;
                int gap = mid - a[i];
                if(gap>diff)    diff = gap, ans = mid;
                else if(gap==diff)  ans = min(ans,mid);
            }else if(a[i+1]<=P || a[i]>=Q){
                continue;
            }else{
                int mid = (a[i]+a[i+1])/2;
                if(mid>=P && mid<=Q){
                    int gap = mid - a[i];
                    if(gap>diff)    diff = gap, ans = mid;
                    else if(gap==diff)  ans = min(ans,mid);
                }else if((a[i]+a[i+1])%2==1 && mid+1>=P && mid+1<=Q){
                    mid++;
                    int gap = a[i+1] - mid;
                    if(gap>diff)    diff = gap, ans = mid;
                    else if(gap==diff)  ans = min(ans,mid);
                }else{
                    if(abs(mid-P) < abs(mid-Q)){
                        int gap = min(abs(P-a[i+1]),abs(P-a[i]));
                        if(gap>diff)    diff = gap, ans = P;
                        else if(gap==diff)  ans = min(ans,P);
                    }
                    if(abs(mid-P) >= abs(mid-Q)){
                        int gap = min(abs(Q-a[i+1]),abs(Q-a[i]));
                        if(gap>diff)    diff = gap, ans = Q;
                        else if(gap==diff)  ans = min(ans,Q);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
