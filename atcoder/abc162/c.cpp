#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int GCD(int a, int b) {
    if (a < b) swap(a, b); 
    if (b == 0) return a;
    return GCD(b, a%b);
}

int main() {
    int K; 
    cin >> K;
    int ret = 0;
    REP(a, K) {
        REP(b, K) {
            REP(c, K) {
                int g = GCD(a+1, GCD(b+1, c+1));
                ret += g;
            }
        }
    } 
    cout << ret << endl;
    return 0;
}