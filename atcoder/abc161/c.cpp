#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    ll n, k;
    cin >> n >> k;
    ll k1 = n%k;
    cout << min(k - k1, k1) << endl;  
    return 0;
}