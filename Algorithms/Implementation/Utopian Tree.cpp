#include <iostream>
using namespace std;

int height(int n) {
    int ret = 1;
    for(int i=0;i<n;i++){
        if((i&1)==0)    ret <<= 1;
        else    ret++;
    }
    return ret;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
