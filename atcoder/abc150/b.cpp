#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, cnt = 0, check=0;
    string s;
    cin >> n >> s;
    bool ca = false, cb = false;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == 'A') {
            check = 1;
            continue;
        }
        if (check == 1 && c == 'B') {
            check = 2;
            continue;
        }
        if (check==2 && c == 'C') ++cnt;
        check = 0; 
    } 
    cout << cnt << endl;
    return 0;
}