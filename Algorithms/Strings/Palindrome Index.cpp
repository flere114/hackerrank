#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[200005];

bool ok(int l,int r){
    for(int i=l,j=r;i<j;i++,j--)
        if(s[i]!=s[j])  return false;
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        int len = strlen(s);
        int ans = -1;
        for(int i=0;i<len/2;i++){
            if(s[i]==s[len-i-1])    continue;
            if(ok(i+1,len-i-1)) ans = i;
            else    ans = len-i-1;
            break;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
