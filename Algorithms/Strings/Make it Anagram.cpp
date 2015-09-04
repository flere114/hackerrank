#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[10004],s2[10004];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf(" %s %s",s1,s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    int c[26];
    memset(c,0,sizeof(c));
    
    for(int i=0;i<len1;i++)    c[s1[i]-'a']++;
    for(int i=0;i<len2;i++)    c[s2[i]-'a']--;
    
    int ans = 0;
    for(int i=0;i<26;i++)
        ans += abs(c[i]);
    
    printf("%d\n",ans);
    
    return 0;
}
