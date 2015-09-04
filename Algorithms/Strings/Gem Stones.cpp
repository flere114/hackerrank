#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[102];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,c[26],use[26];
    scanf(" %d",&N);
    memset(c,0,sizeof(c));
    
    for(int n=0;n<N;n++){
        scanf(" %s",s);
        memset(use,0,sizeof(use));
        int len = strlen(s);
        for(int i=0;i<len;i++)
            if(use[s[i]-'a']==0)
                c[s[i]-'a']++, use[s[i]-'a'] = 1;
    }
    int ans = 0;
    for(int i=0;i<26;i++)
        if(c[i]==N)
            ans++;
    printf("%d\n",ans);
    
    return 0;
}
