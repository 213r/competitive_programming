#include <bits/stdc++.h>
using namespace std;


int main () {
    int n, k, r, s, p; 
    cin >> n >> k;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    int ret = 0;
    vector<int> loose(n, 0);
    for (int i = 0; i < n; ++i) {
        if ((i >= k) && (t[i] == t[i-k]) && !loose[i-k]) {
            loose[i] = 1;
            continue;
        }
        if (t[i] == 'r') ret += p;
        else if (t[i] == 's') ret += r;
        else ret += s;

    }
    cout << ret << endl;
    return 0;
}