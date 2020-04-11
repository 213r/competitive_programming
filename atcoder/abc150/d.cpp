#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n; cin >> n;
    vector<int> c;
    rep(i,n) cin >> c[n];

    int ret = 1;   
    int tn = n, mb = 2;
    while (tn) {
        if (tn & 1) ret *= mb;
        

    }
 
    cout << abs(b - a) << endl;
}