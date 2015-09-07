#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int t=0,N,a,b;t<T && cin >> N >> a >> b;t++){
        v.clear();
        for(int i=0;i<N;i++)
            v.push_back(a*i+b*(N-i-1));
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<v.size();i++)
            if(i==0)    printf("%d",v[0]);
            else    printf(" %d",v[i]);
        printf("\n");
    }
    return 0;
}
