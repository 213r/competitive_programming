#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const int MOD = 1000000007; 

int main() {
    int n, y;
    cin >> n >> y;
    y /= 1000;
    for (int a = 0, d; d=y-n-9*a, d>=0; ++a) {
        if (d%4==0) {
            int b = d/4;
            int c = n-a-b;
            if (c < 0) continue;
            cout << a << " " << d/4 << " " << c << endl;
            return 0;
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}