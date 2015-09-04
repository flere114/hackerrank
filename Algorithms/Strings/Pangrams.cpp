#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[1003];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    gets(s);
    int len = strlen(s);
    int c[30];
    memset(c,0,sizeof(c));
    
    for(int i=0;i<len;i++){
        if(s[i]>='A' && s[i]<='Z')  c[s[i]-'A'] = 1;
        if(s[i]>='a' && s[i]<='z')  c[s[i]-'a'] = 1;
    }
    int ans = 0;
    for(int i=0;i<26;ans+=c[i],i++);
    if(ans==26) puts("pangram");
    else puts("not pangram");
    
    return 0;
}
