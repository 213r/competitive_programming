#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;

int main() {
    string s, t, u; 
    int a, b;
    cin >> s >> t;
    cin >> a >> b;
    cin >> u;

    if (s == u) a--;
    else b--;
    cout << a << " " << b << endl;

    return 0;
}
