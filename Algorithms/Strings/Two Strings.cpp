#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[100005],s2[100005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %s %s",s1,s2);
        int len1 = strlen(s1), len2 = strlen(s2);
        int c1[26],c2[26];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<len1;i++) c1[s1[i]-'a']++;
        for(int i=0;i<len2;i++) c2[s2[i]-'a']++;
        int ans = 0;
        for(int i=0;i<26;i++)
            if(c1[i]>0 && c2[i]>0)
                ans = 1;
        if(ans==1)  printf("YES\n");
        else    printf("NO\n");
    }
    
    return 0;
}
