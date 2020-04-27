#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    string s; 
    cin >> s;
    int pass = 0, bpass = 0;
    for (char c: s) {
        string o = "No";
        if (c == 'a') {
            if (a+b > pass) {
                ++pass;
                o = "Yes";
            } 
        } 
        if (c == 'b') {
            if (a+b > pass && b > bpass) {
                ++pass;
                ++bpass;
                o = "Yes";
            }
        }
        cout << o << endl; 
    }
    return 0;
}