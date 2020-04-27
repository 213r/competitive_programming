#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    string s;
    cin >> s;
    vector<int> as(s.size()+1, 0);
    int p = 0;
    REP(i, s.size()) {
        if (s[i] == '<') {
            as[i] = p++;
        } else {
            as[i] = p;
            p = 0;
        }
    } 
    if (s[s.size()-1] == '<') as[s.size()] = p; 
    p = 0;
    for(int i = s.size()-1; i >= 0; --i) {
       if (s[i] == '>') {
            as[i+1] = p++;
        } else {
            as[i+1] = max(as[i+1], p);
            p = 0;
        }
    }
    if (s[0] == '>') as[0] = p; 
    ll ret = 0;
    REP(i, s.size()+1) ret +=as[i]; 
    cout << ret << endl;
    return 0;
}