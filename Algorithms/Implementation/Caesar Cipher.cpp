#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[103];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int len,k;
    scanf(" %d",&len);
    scanf(" %s %d",s,&k);
    
    for(int i=0;i<len;i++){
        if(s[i]>='a' && s[i]<='z'){
            int now = s[i]-'a';
            now = (now+k)%26;
            s[i] = now + 'a';
        }else if(s[i]>='A' && s[i]<='Z'){
            int now = s[i]-'A';
            now = (now+k)%26;
            s[i] = now + 'A';
        }
    }
    printf("%s\n",s);
    
    return 0;
}
