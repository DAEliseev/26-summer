#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long md = 1000000007;
    int n;
    cin >> n;
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        sm = (sm + x) % md;
    }

    long long pw = 1;
    for (int i = 1; i < n; ++i) {
        pw = pw * 2 % md;
    }

    cout << (sm * pw % md + md) % md << '\n';

    return 0;
}
