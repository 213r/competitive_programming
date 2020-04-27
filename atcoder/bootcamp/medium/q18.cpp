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
    int d[3][3]; 
    rep(i, 3) { 
        rep(j, 3) {
            cin >> d[i][j]; 
        }
    } 

    rep(j, 2) {
        rep(i, 2) {
            if (d[i+1][j]-d[i+1][j+1] 
            != d[0][j] - d[0][j+1]) {
                cout << "No" << endl;
                return 0;    
            } 
        }
    }
    
    rep(i, 2) {
        rep(j, 2) {
            if (d[i+1][0]-d[i][0] 
            != d[i+1][j+1] - d[i][j+1]) {
                cout << "No" << endl;
                return 0;    
            } 
        }
    }
    cout << "Yes" << endl;
    return 0;
}