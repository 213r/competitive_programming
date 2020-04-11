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

   
    return 0;
}