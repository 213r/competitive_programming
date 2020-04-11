#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

bool check(ll a) {
    int k1 = a%10;
    a /= 10;
    while(a) {
        int k2 = a%10;
        if (abs(k1-k2) > 1) return false; 
        a /=10;
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    if (k < 10) {
        cout << k << endl;
        return 0; 
    } 
    ll a = 10; 
    int cnt = 10; 
    while(1) {
        cout << cnt << ", " << a << endl;
        if (check(a)) { 
            if (cnt == k) {
                cout << a << endl; 
                return 0; 
            }
            ++cnt; 
        } 
        ++a;
    }
    return 0;
}