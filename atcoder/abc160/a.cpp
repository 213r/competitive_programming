#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 


int main() {
    string s;
    cin >> s; 
    if ((s[2] == s[3]) && (s[4] == s[5])) 
        cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}