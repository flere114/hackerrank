#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1003],b[1003],use[1003];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int t=0,N,K;t<T && cin >> N >> K;t++){
        for(int i=0;i<N && cin >> a[i];i++);
        for(int i=0;i<N && cin >> b[i];i++) use[i] = 0;
        int ok = 1;
        for(int i=0;i<N && ok==1;i++){
            int pos = -1;
            for(int j=0;j<N;j++){
                if(use[j]==1)   continue;
                if(a[i]+b[j]<K) continue;
                if(pos==-1 || b[j]<b[pos]) pos = j;
            }
            if(pos==-1) ok = 0;
            else use[pos] = 1;
        }
        if(ok==1)   printf("YES\n");
        else    printf("NO\n");
    }
    
    return 0;
}
