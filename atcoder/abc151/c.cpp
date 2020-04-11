#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n,m; 
    cin >> n >> m;
    vector<bool> accs(n+1, false);
    vector<int> wa_counts(n+1, 0);
    int acc_count = 0, wa_count = 0;
    rep(i, m) {
        string s;
        int p;
        cin >> p >> s;
        if (s == "AC") {
            if (!accs[p]) {
                accs[p] = true;
                acc_count += 1;
                wa_count += wa_counts[p];
            }
        } else {
            if (!accs[p]) {
                wa_counts[p] += 1;
            }
        }
    }
    cout << acc_count << " " << wa_count << endl;
    return 0;
}