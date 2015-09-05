#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int a[100005],tree[100005<<2];
vector <int> v;

void update(int x,int L,int R,int r){
    if(L==R){
        tree[r]++;
        return;
    }
    int mid = (L+R)>>1;
    if(x<=mid)  update(x,L,mid,r<<1);
    else    update(x,mid+1,R,r<<1|1);
    tree[r] = tree[r<<1] + tree[r<<1|1];
}
int query(int x,int y,int L,int R,int r){
    if(x<=L && R<=y){
        return tree[r];
    }
    int mid = (L+R)>>1, ret = 0;
    if(x<=mid)  ret += query(x,y,L,mid,r<<1);
    if(mid<y)   ret += query(x,y,mid+1,R,r<<1|1);
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d",&N)==1;t++){
        v.clear();
        for(int i=0;i<N && scanf(" %d",&a[i])==1;i++)
            v.push_back(a[i]);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        memset(tree,0,sizeof(tree));
        long long ans = 0;
        for(int i=0;i<N;i++){
            int rank = lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
            ans += query(rank+1,v.size(),1,v.size(),1);
            update(rank,1,v.size(),1);
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
