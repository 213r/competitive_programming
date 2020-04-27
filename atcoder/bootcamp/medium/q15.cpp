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
    string s;
    cin >> s;
    int n = s.size();
    const string keyence = "keyence";
    if (n == 7) {
        string ret = (s == keyence ? "YES" : "No");
        cout << ret << endl;
        return 0;
    }
    rep(i, 8) {
        bool is_ok = true;
        if (i > 0 && s[i-1]!=keyence[i-1]) continue;
        rng(j, i, 7) if(s[j+n-7] != keyence[j]){
            is_ok = false; 
            break;
        } 
        if (is_ok) {
            cout << "YES" << endl;
            return 0; 
        }
    }
    cout << "NO" << endl;
    return 0;
}