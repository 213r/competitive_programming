#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc_price(ll a, ll b,ll n) {
    int d = 0;
    ll n1 = n;
    while (n1) {
        n1 /= 10;
        ++d; 
    }
    return a * n + b * d;
}

int main () {
    ll a, b, l=0, h=1E9, x;
    cin >> a >> b >> x;
    int n = (l+h) / 2;
    while (l + 1< h) {
        ll pr = calc_price(a, b, n); 
        (pr <= x? l : h) = n;
        n = (l+h) / 2;
    } 
    ll pr = calc_price(a, b, h); 
    if (pr > x) --h;
    cout << h << endl;
    return 0;
}