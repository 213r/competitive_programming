#include <bits/stdc++.h>
using namespace std;

int main () {
    int h, w; 
                cout << 1 <<  endl;
    cin >> h >> w;
                cout << 2 <<  endl;

    int a[90][90];
    int b[90][90];
                cout << h << "," << w << "," <<   endl;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
                cout << i << "," << j << "," <<   endl;
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
                cout << i << "," << j << "," <<   endl;
            cin >> b[i][j];
        }
    }

    const int maxdp = 20000;
    int dp[90][90][maxdp];
    int k = abs(a[0][0]-b[0][0]);
    dp[0][0][k] = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < maxdp; ++k) {
                cout << i << "," << j << "," <<  k << endl;
                if (dp[i][j][k]) {
                    if (j < w-1) {
                        int d = abs(a[i][j+1]-b[i][j+1]);
                        int k1 = k+d;
                        int k2 = abs(k-d);
                        dp[i][j+1][k1] = 1;
                        dp[i][j+1][k2] = 1;
                    }
                    if (i < h-1) {
                        int d = abs(a[i+1][j]-b[i+1][j]);
                        int k1 = k+d;
                        int k2 = abs(k-d);
                        dp[i+1][j][k1] = 1;
                        dp[i+1][j][k2] = 1;
                    }
                }
            }
        }
    }
    for (int k = 0; k < maxdp; ++k) {
        if (dp[h-1][w-1][k]) {
            cout << k << endl;
            break; 
        }
    } 
    return 0;
}