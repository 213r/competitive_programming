#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; 
    string s, ret = ""; 
    cin >> n >> s;
    for (char c : s) {
        ret += 'A' + (c-'A'+n)%26;
    }
    cout << ret << endl;
    return 0;
}