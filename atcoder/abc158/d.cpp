#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    string s;
    cin >> s;
    list<char> ls(s.begin(), s.end());
    int q;
    cin >> q;
    int order = 1;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) order *= -1;
        else {
            int o;
            char p;
            cin >> o >> p;
            if (o == 2) o = -1;
            o *= order;
            if (o == 1) ls.push_front(p);
            else ls.push_back(p);
        }
    } 
    if (order < 0) reverse(ls.begin(), ls.end());
    for (char x : ls) cout << x;
    cout << endl;
    return 0;
}