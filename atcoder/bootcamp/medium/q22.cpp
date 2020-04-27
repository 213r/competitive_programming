#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const int MOD = 1000000007; 

int main() {
    int n, k;
    cin >> n >> k;
    double ret = 0;
    rep(l, n) {
        if (l >= k) ret++; 
        else {
            int m = ceil(log2(double(k)/(l+1)));
            ret += 1.0 / double(pow(2, m)); 
        }
    } 
    ret /= n;
    cout << setprecision(10) <<  ret << endl;
    return 0;
}