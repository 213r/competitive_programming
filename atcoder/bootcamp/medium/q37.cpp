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

int check(vector<int>& hs) {
    bool is_flag = false;
    rep(i, hs.size()) {
        if(hs[i]) {
            is_flag = true;
            hs[i]--;
        } else {
            if (is_flag) {
                return true;
            }  
        } 
    }
    return is_flag;
}

int main() {
    int n; 
    cin >> n;
    vector<int> hs(n);
    rep(i, n) cin >> hs[i];
    int cnt = 0; 
    while(check(hs)) {
        cout << endl;
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}