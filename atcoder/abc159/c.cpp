#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;

int main() {
    int l; 
    cin >> l; 
    double l1 = (double)(l) / 3.0;
    double ret = l1 * l1 * l1;
    cout << setprecision(16) << ret << endl;
    return 0;
}