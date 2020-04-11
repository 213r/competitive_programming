#include <bits/stdc++.h>
using namespace std;

int A[20];
int x[20][20];
int y[20][20];

int counter(int bit) {
    if (bit == 0) return 0;
    return (bit & 1) + counter(bit >> 1);


}
int main () {
    int n; 
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        for (int j = 1; j <= A[i]; ++j) {
            cin >> x[i][j] >> y[i][j];
        }
    } 

    int ret = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (!((bit >> i-1)&1)) continue; 
            for (int j = 1; j <= A[i]; ++j) {
                if (((bit >> (x[i][j]-1))&1)^y[i][j]) ok = false;
            }
        }
        if (ok) ret = max(ret, counter(bit));
    }
    cout << ret << endl;
    return 0;
}