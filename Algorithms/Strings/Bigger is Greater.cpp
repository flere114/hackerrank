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
    int T;
    scanf(" %d",&T);
    
    for(int t=0;t<T;t++){
        scanf(" %s",s);
        if(next_permutation(s,s+strlen(s))==NULL)
            printf("no answer\n");
        else    printf("%s\n",s);
    }
    
    return 0;
}
