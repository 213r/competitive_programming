#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    int n = s.length(), ret = 0;
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n-i-1]) ret += 1;
    }
    cout << ret << endl;
    return 0;
}