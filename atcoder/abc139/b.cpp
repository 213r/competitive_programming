#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int a, b;
    cin >> a >> b;
    int ret = (b-1)/(a-1);
    if ((b-1)%(a-1)) ret++;
    cout << ret << endl; 
    return 0;
}