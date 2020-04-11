#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;
 
int main() {
    int n; cin >> n;
    vector<int> P(n),Q(n);
    rep(i,n) cin >> P[i];
    rep(i,n) cin >> Q[i];
    
    vector<int> v(n);
    iota(v.begin(), v.end(), 1); 
    ll a = 0,b  = 0;
    ll cnt = 1;
    do{
        int p = 0,q = 0;
        rep(i,n){
            if(v[i] == P[i]) p++;
            if(v[i] == Q[i]) q++;
        }
        if(p == n) a = cnt;
        if(q == n) b = cnt;
        cnt++;
    } while(next_permutation(v.begin(), v.end()));
 
    cout << abs(b - a) << endl;
}