#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <long long> v;
    for(long long i=1;i*i<=1000000000;i++)
        v.push_back(i*i);
    
    int T;
    long long a,b;
    cin >> T;
    for(int t=0;t<T && cin >> a >> b;t++)
        printf("%d\n",upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a));
    
    
    return 0;
}
