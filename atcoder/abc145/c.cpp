#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
 
typedef long long ll;
const int MOD = 1000000007; 
 
int main() {
    int n;
    cin >> n;
    vector<vector<double>> dis(n, vector<double>(n, 0));
    vector<pair<int, int>> xy;
    for(int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        xy.push_back({x, y});
    }
    for(int i = 0; i < n-1; ++i) {
        for(int j = i+1; j < n; ++j) { 
            double xd = xy[i].first - xy[j].first;
            double yd = xy[i].second - xy[j].second;
            double d = sqrt(xd*xd+yd*yd);
            dis[i][j] = dis[j][i] = d;
        }
    }
    vector<int> inds(n);
    iota(inds.begin(), inds.end(), 0);
    double ans = 0; 
    int count = 0; 
    do {
        for(int i = 0; i < n-1; ++i) {
            ans += dis[inds[i]][inds[i+1]];
        }
        ++count;
    } while(next_permutation(inds.begin(), inds.end()));
    ans /= count;
    cout << setprecision(16) << ans << endl;
    return 0;
}