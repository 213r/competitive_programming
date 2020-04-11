#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    int n;
    vector<set<int>> idxs(26);
    cin >> n;
    rep(i, n) {
        char c;
        cin >> c;
        idxs[c-'a'].insert(i);
    }
    int q;
    vector<int> ans;
    cin >> q;
    rep(i, q) {
        int s;
        cin >> s;
        if (s == 1) {
            int iq;
            char cq;
            cin >> iq >> cq;
            --iq;
            rep(j, 26) {
                if (idxs[j].count(iq)) {
                    idxs[j].erase(iq);
                    idxs[cq-'a'].insert(iq);
                }
            }
        } else {
            int lq, rq;
            cin >> lq >> rq;
            --lq; rq;
            int c = 0;
            rep(j, 26) {
                if (idxs[j].size()) {
                    char cc = j + 'a';
                    auto lit = idxs[j].lower_bound(lq);
                    if (lit != idxs[j].end() && *lit < rq) ++c;
                }
            }
            ans.push_back(c);
        }
    }
    for (int a : ans) cout << a << endl;
    return 0;
}