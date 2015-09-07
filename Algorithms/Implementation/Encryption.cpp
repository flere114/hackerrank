#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[100];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf(" %s",s);
    int len = strlen(s);
    int L = floor(sqrt(len)), R = ceil(sqrt(len));
    int N,M;
    if(L*R >= len)  N = L, M = R;
    else    N = M = R;
    
    for(int i=0;i<M;i++){
        if(i>0) printf(" ");
        for(int j=i;j<len;j+=M)
            printf("%c",s[j]);
    }
    printf("\n");
    
    return 0;
}
