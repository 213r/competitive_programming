#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    string s;
    cin >> s;
    int keta = 100;
    int v = 0;
    REP(i, 3) {
        int si = s[i] - '0';
        if (si < 0 || si > 9) {
            cout << "error" << endl; 
            return 0; 
        }         
        v += si * keta;
        keta /= 10;
    } 
    cout << v * 2 << endl;
    return 0;
}