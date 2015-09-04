#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


int main() {
    
    string s;
    cin>>s;
    
    int flag = 0;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string
    int len = s.length();
    int c[26];
    memset(c,0,sizeof(c));
    
    for(int i=0;i<len;i++)
        c[s[i]-'a']++;
    int odd = 0;
    for(int i=0;i<26;i++)
        if(c[i]&1)
            odd++;
    if(odd>1 || (odd==1 && (len&1)==0) || (odd==0 && (len&1)==1)) flag = 0;
    else flag = 1;
    
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
