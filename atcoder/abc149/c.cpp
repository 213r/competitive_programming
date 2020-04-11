#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x, vector<int>& primes) {
    for (int p : primes) {
        if (x%p == 0) return false;
    }
    primes.push_back(x);
    return true;
}

int solve(int x) {
    if (x == 2) return 2;
    vector<int> primes = {2};
    int y = 3;
    while (!(is_prime(y, primes) && y >= x)) {
        y += 1;
    }
    return y;
}

int main () {
    int x; 
    cin >> x;
    cout << solve(x) << endl;
    return 0;
}