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
    int n;
    cin >> n;
    vector<int> as(n); 
    rep(i, n) cin >> as[i]; 
    bool isreset = true, preup;
    int ret = 1;
    rep(i, n-1) {
        int d = as[i+1] - as[i];
        if (d==0) continue;
        if(isreset) {
            isreset = false;
            preup = d > 0;
        }
        else {
            if (d>0 ^ preup) {
                ++ret;
                preup = d > 0;
                isreset = true;
            }
        }
    } 
    cout << ret << endl;
    return 0;
}