#include <bits/stdc++.h>
using namespace std;

int main () {
    unordered_map<string, int> to_sunday 
    {
        {"SUN",  7},
        {"MON",  6},
        {"TUE",  5},
        {"WED",  4},
        {"THU",  3},
        {"FRI",  2},
        {"SAT",  1}
    };
    string s; 
    cin >> s;
    cout << to_sunday[s] << endl;
    return 0;
}