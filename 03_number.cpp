#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> dp(n + 1);

    for (int i = 2; i <= n; ++i) {
        long long mn = dp[i - 1];
        if (i % 2 == 0) {
            mn = min(mn, dp[i / 2]);
        }
        if (i % 3 == 0) {
            mn = min(mn, dp[i / 3]);
        }
        dp[i] = mn + i;
    }

    cout << dp[n] << '\n';

    return 0;
}
