#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        int len = strlen(s);
        if(len&1){
            printf("-1\n");
            continue;
        }
        int c[26];
        memset(c,0,sizeof(c));
        for(int i=0;i<len;i++)
            if(i<len/2) c[s[i]-'a']++;
            else    c[s[i]-'a']--;
        int ans = 0;
        for(int i=0;i<26;i++)
            ans += abs(c[i]);
        printf("%d\n",ans>>1);
    }
    
    return 0;
}
