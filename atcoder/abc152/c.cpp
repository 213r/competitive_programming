#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n, mp = int(1E6), cnt = 0;
    cin >> n;
    rep(i, n) {
        int p;
        cin >> p;
        if (mp >= p) {
            ++cnt;
            mp = p;
        }
    }
    cout << cnt << endl;
    return 0;
}