#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define print(a) cout << (a) << endl; 
typedef long long ll;
// https://atcoder.jp/contests/abc159/submissions/11134399
const int INF = 1e9; 

int main() {
    int h, w, K; 
    cin >> h >> w >> K;
    vector<string> s(h); 
    rep(i, h) {
        string l;
        cin >> s[i];
    } 
    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));
    rep(i, h) rep(j, w) {
        if (s[i][j] == '1') dp[i+1][j+1] = 1;
    }
    rep(i, h+1) rep1(j, w+1) {
        dp[i][j] += dp[i][j-1];
    }
    rep1(i, h+1) rep(j, w+1) {
        dp[i][j] += dp[i-1][j];
    }
    
    int ret = INF;
    rep(i, 1 << (h-1)) {
        vector<int> v;
        v.push_back(0);
        rep(j, h - 1){
            if ((i >> j) & 1) 
                v.push_back(j+1); 
        }
        v.push_back(h);
        int sum = v.size() - 2;
        int bef = 0;
        for(int j = bef; j < w; j++) {
            int flag = 0; 
            rep(k, v.size()-1) {
                if (dp[v[k+1]][j+1] - dp[v[k+1]][bef] - dp[v[k]][j+1] 
                    + dp[v[k]][bef] > K) {
                        if (bef == j) {
                            flag = 1;
                            sum = INF;
                            break;
                        }
                        bef = j;
                        sum++;
                        break;
                    }
            }
            if (flag == 1) break;
        }
        ret = min(ret, sum);
    }
    cout << ret << endl;
    return 0;
}