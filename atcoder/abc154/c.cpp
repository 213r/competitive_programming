#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;

int main() {
    int n; 
    cin >> n;
    unordered_set<int> aa;
    rep(i, n) {
        int a;
        cin >> a;
        aa.insert(a);
    }
    if (aa.size() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}