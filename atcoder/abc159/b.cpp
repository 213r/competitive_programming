#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;

bool check(string&s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }
    return true;
}

int main() {
    string s; 
    cin >> s; 
    int n = s.size();
    if (check(s, 0, n-1) && check(s, 0, (n-3)/2) 
        && check(s, (n+1)/2, n -1))
        cout << "Yes" << endl;
    else cout << "No" << endl; 
}