#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;

int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> ps(n);
    rep(i, n) cin >> ps[i]; 
    
    int mi = 0, mv = 0, pk = 0; 
    rep(i, n) {
        pk += ps[i];
        if (i >= k) pk -= ps[i-k];
        if (i >= k-1) {
            if (mv < pk) mi = i, mv = pk;  
        }
    }
    double ret = 0;
    rep(i, k) {
        double p = ps[mi-i];
        ret += (p+1) / 2;
    }
    cout << setprecision(10) << ret << endl;
    return 0;
}