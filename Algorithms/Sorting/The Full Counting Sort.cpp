#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector <string> v[100];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    
    string s;
    for(int n=0,x;n<N && cin >> x >> s;n++){
        if(n<N/2)   v[x].push_back("-");
        else    v[x].push_back(s);
    }
    for(int i=0;i<100;i++)
        for(int j=0;j<v[i].size();j++)
            cout << v[i][j] << " ";
    
    return 0;
}
