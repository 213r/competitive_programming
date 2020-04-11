#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, n) for (int i = s; i < n; i++)
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    string s;
    cin >> s;
    vector<string> ss;
    string ts = "";
    bool open = false;
    for (char c : s) {
        int ci = c - 'A'; 
        if (ci >= 0 && ci <= 25) {
            ts += ci + 'a';
            if (open) {
                open = false;
                ss.push_back(ts);
                ts = "";
            } else open = true; 
        } else {
            ts += c;
        } 
    }
    sort(ss.begin(), ss.end()); 
    string ret = "";
    for(auto& s : ss) {
        char cb = s[0] - 'a' + 'A';
        s[0] = cb;  
        char ce = s[s.size()-1] - 'a' + 'A';
        s[s.size()-1] = ce;  
        ret += s;
    }
    cout << ret << endl; 
    return 0;
}