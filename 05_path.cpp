#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> dg(n), dp(n, 1), pr(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        ++dg[v];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (dg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                pr[v] = u;
            }
            if (--dg[v] == 0) {
                q.push(v);
            }
        }
    }

    int v = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> an;
    while (v != -1) {
        an.push_back(v + 1);
        v = pr[v];
    }
    reverse(an.begin(), an.end());

    cout << an.size() << '\n';
    for (int x : an) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
