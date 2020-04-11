#include <bits/stdc++.h>
using namespace std;

int main () {
    int q;
    cin >> q;
    vector<int> cbuf(q);
    for (int i = 0; i < q; ++i) cin >> cbuf[i];
    vector<int> cs;
    for (int c : cbuf) {
        auto itr = find(cs.begin(), cs.end(),c);
        if (itr != cs.end()) cs.erase(itr);
        else {
            if (cs.size() > 4) cs.erase(cs.begin());
        } 
        cs.push_back(c);
        for (auto itr = cs.rbegin(); itr != cs.rend(); ++itr) cout << *itr << " ";
        cout << endl;
    } 

    return 0;
}