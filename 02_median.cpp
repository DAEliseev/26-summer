#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<long long> l;
    priority_queue<long long, vector<long long>, greater<long long>> r;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        if (l.empty() || x <= l.top()) {
            l.push(x);
        } else {
            r.push(x);
        }
        if (l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        }
        if (l.size() > r.size() + 1) {
            r.push(l.top());
            l.pop();
        }
        cout << l.top() << '\n';
    }

    return 0;
}
