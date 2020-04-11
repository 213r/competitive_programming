#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cuma(n, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cuma[i] = i > 0 ? cuma[i-1] + a : a;
    }
    unordered_map<int, int> ss;
    for (int i = 1; i < k+1; ++k) {

    }
    cs[as[0]].push_back(1);


    return 0;
}