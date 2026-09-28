#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, f;
    cin >> n >> m >> s >> f;
    --s;
    --f;
    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }

    const int inf = 1000000000;
    vector<int> ds(n, inf);
    deque<int> q;
    ds[s] = 0;
    q.push_back(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto e : g[u]) {
            int v = e.first;
            int w = e.second;
            if (ds[v] <= ds[u] + w) {
                continue;
            }
            ds[v] = ds[u] + w;
            if (w == 0) {
                q.push_front(v);
            } else {
                q.push_back(v);
            }
        }
    }

    cout << ds[f] << '\n';

    return 0;
}
