#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> s(q);
    vector<vector<char>> f(n, vector<char>(n, 'N'));
    REP(i, q) {
        int k;
        cin >> k;
        if (k == 1) {
            int a, b;
            cin >> a >> b;
            --a; --b;
            f[a][b] = 'Y';
        } else if (k == 2) {
            int a;
            cin >> a; --a;
            REP(i, n) {
                if (f[i][a] == 'Y') f[a][i] = 'Y';
            }
        } else {
            int a;
            cin >> a; --a;
            vector<int> xs;
            REP(i, n) {
                if (f[a][i] == 'Y') xs.push_back(i);
            } 
            for(int x : xs) {
                REP(j, n) {
                    if (f[x][j] == 'Y' && a != j) f[a][j] = 'Y';
                }
            }
        }
    }  
    REP(i, n) {
        REP(j, n) cout << f[i][j];
        cout << endl; 
    } 
    return 0;
}