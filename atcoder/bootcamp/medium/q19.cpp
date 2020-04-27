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
    vector<int> as(3);
    rep(i, 3) cin >> as[i];
    cin >> n;
    sort(all(as));
    int cnt = 0;
    for(int i=0; i*as[2] <= n; ++i) {
        for(int j = 0; j*as[1] + i*as[2] <= n; ++j) {
            if((n-j*as[1]-i*as[2])%as[0]==0) ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}