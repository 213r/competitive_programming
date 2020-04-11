#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n, ret = 0; 
    cin >> n;
    vector<int> times(n);
    vector<string> titles(n);
    rep(i,n) cin >> titles[i] >> times[i];
    string key;
    bool check = false;
    cin >> key; 
    rep(i, n) {
        if (check) {
            ret += times[i];
        }
        if (titles[i] == key) check = true;
    }    
    cout << ret << endl;
    return 0;
}