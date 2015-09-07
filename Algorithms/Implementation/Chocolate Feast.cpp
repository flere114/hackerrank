#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,c,m;
    cin>>t;
    while(t--){
        cin>>n>>c>>m;
        int answer=0, wrapper = 0;
        // Computer answer
        answer += n/c;
        wrapper += n/c;
        
        while(wrapper >= m){
            int get = wrapper / m;
            answer += get;
            wrapper %= m;
            wrapper += get;
        }
        
        cout<<answer<<endl;
    }
    return 0;
}
