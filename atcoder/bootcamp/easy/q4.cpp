#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = s; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 

int main() {
    int n;
    cin >> n;
    int ret;
    if (n*100%108==0) {
        ret = n*100/108;
    } else {
        ret = n*100/108;
        ret++;
        int cmpi = ret*1.08;
        if (cmpi != n) {
            cout << ":(" << endl;
            return 0; 
        }
    }  
    cout << ret << endl;
    return 0;
}