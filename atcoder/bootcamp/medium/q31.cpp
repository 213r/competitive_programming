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
    int n, m;
    cin >> n;
    int c4=0, c2=0, co=0; 
    rep(i, n) {
        int a; cin >> a;
        if (a%4==0) c4++;
        else if (a%2==0) c2++;
        else co++;
    } 
    co += c2%2;
    cout << (c4 < co -1 ? "No" : "Yes") << endl;
    return 0;
}