#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int a, b;
    cin >> a >> b;
    string as = "", bs = "";
    rep(i, a) as += to_string(b);
    rep(i, b) bs += to_string(a);
    if (as <= bs) cout << as << endl;
    else cout << bs << endl;

    return 0;
}