#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i]; 
    int ml = 0; 
    rep(i, n-1) {
        ml = max(ml, a[i+1]-a[i]); 
    }
    ml = max(ml, k-a[n-1]+a[0]);
    cout << k - ml << endl;
    return 0;
}