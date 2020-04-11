#include <bits/stdc++.h>
using namespace std;

int dfs(char c, int i, int n, unordered_map<char, int>& ss) {
    if (i == n) return 1;
    int ret = 0;
    for (auto& sm:ss) {
        if (sm.first == c || ss[sm.first] == 0) continue;
        --ss[sm.first];
        ret += dfs(sm.first, i+1, n, ss);
        ++ss[sm.first];
    }
    return ret;
}
int solve(string&s) {
    unordered_map<char, int> ss;
    for (char c : s) ss[c] += 1;
    return dfs('-', 0, s.size(), ss);
}

int main () {
    string s;
    cin >> s;
    int ret = solve(s);
    cout << ret << endl;
    return 0;
}