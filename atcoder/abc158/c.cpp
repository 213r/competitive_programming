#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    int a, b;
    cin >> a >> b; 
    rep(i, 2000) {
        int ac = i*0.08;
        int bc = i * 0.1;
        if (ac == a && bc == b) {
            cout << i << endl;
            return 0;
        } 
    } 
    cout << -1 << endl;
    return 0;
}