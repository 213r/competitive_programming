#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> dis(n+1, 0);
    rep(i, 1, n) {
        rep(j, i+1, n+1) {
            int d = min(abs(x-i)+abs(y-j)+1, j-i);
            dis[d]++;            
        }
    }
    rep(i, 1, n) {
        cout << dis[i] << endl;
    } 
    return 0;
}