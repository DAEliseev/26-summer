#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, r;
    cin >> s;
    r = s;
    reverse(r.begin(), r.end());
    string t = s + "#" + r;
    vector<int> p(t.size());

    for (int i = 1; i < (int)t.size(); ++i) {
        int j = p[i - 1];
        while (j > 0 && t[i] != t[j]) {
            j = p[j - 1];
        }
        if (t[i] == t[j]) {
            ++j;
        }
        p[i] = j;
    }

    cout << p.back() << '\n';

    return 0;
}
