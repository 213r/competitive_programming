#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    unordered_set<int> s;
    ll n, dup;
    cin >> n;
    ll tot = 0;
    REP(i, n) {
        int a;
        cin >> a;
        if (s.find(a) != s.end()) dup = a;  
        else {
            tot += a; 
            s.insert(a);
        }
    }
    ll ms = n*(n+1)/2 - tot;
    if (ms == 0) cout << "Correct" << endl;
    else cout << dup << " " << ms << endl;
    return 0;
}