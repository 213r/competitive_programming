#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a == b && b != c) || (a != b && b == c) 
        || (a == c && c != b)) {
        cout << "Yes" << endl;
    }  else cout << "No" << endl;
    return 0;
}