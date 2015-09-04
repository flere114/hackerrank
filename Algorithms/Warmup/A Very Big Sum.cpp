#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    long long ans = 0;
    cin >> N;
    for(int i=0,x;i<N && cin >> x;i++)
        ans += x;
    cout << ans << endl;
    return 0;
}
