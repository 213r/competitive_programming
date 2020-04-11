#include <bits/stdc++.h>
using namespace std;

int main () {
    long long  a, b, k, k1;
    cin >> a >> b >> k;
    k1 = min(a, k); 
    a -= k1;
    b -= min(b, k-k1);
    cout << a << " " << b << endl;
    return 0;
}