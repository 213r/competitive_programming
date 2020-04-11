#include <bits/stdc++.h>
using namespace std;

string solve(string&s , string& t) {
    if (s.size() + 1 < t.size())  return "NO";
    if (s.size() == t.size()) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) ++cnt;
            if (cnt > 1) return "NO";
        }
    } else {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[j] != t[i]) {
                if (i == j) continue; 
                else return "NO"; 
            }
            ++j;
        }
    }
    return "YES";
}

int main () {
    string s, t;
    cin >> s;
    cin >> t;
    if (s.size() > t.size()) {
        swap(s, t);
    }
    string ret = solve(s, t);
    cout << ret << endl; 
    return 0;
}