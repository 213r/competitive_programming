#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n;;
    cin >> n;
    vector<int> reds, blues;
    REP(i, n) {
        int x; 
        char c;
        cin >> x >> c;
        if (c == 'R') reds.push_back(x);
        else blues.push_back(x);
    }
    sort(reds.begin(), reds.end());
    sort(blues.begin(), blues.end());
    for(int r : reds) cout << r << endl;
    for(int b : blues) cout << b << endl;
    return 0;
}