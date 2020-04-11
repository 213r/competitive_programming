#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    ll n, a, b;
    cin >> n >> a >> b; 
    ll ia = n / (a+b);
    ll pa = n % (a+b);
    ll ret = ia * a + min(pa, a);
    cout << ret << endl;
}