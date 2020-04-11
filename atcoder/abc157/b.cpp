#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n;
    unordered_map<int, int> as;
    vector<int> c(10, 0);
    for (int i = 1; i < 10; ++i) {
        int a;
        cin >> a;
        as[a] = i;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (as[b]) {
            c[as[b]] = 1; 
        }
    }
    if ((c[1] * c[2] * c[3]) 
     || (c[4] * c[5] * c[6])  
     || (c[7] * c[8] * c[9])  
     || (c[1] * c[4] * c[7])  
     || (c[2] * c[5] * c[8])  
     || (c[3] * c[6] * c[9])  
     || (c[1] * c[5] * c[9])  
     || (c[3] * c[5] * c[7])  
    ){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    //for (int i = 1; i < 10; ++i) cout << i << "," << c[i] << endl;
    return 0;
}