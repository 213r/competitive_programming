#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;
    for (int i = 1; i <= s.size(); ++i) {
        cout << s.substr(0, i) << endl;
    }
    return 0;
}