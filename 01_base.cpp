#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    string s;
    cin >> a >> b >> s;

    unsigned long long n = 0;
    for (char c : s) {
        int d = isdigit(c) ? c - '0' : c - 'a' + 10;
        n = n * a + d;
    }

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    string t;
    while (n > 0) {
        int d = n % b;
        t += d < 10 ? char('0' + d) : char('a' + d - 10);
        n /= b;
    }
    reverse(t.begin(), t.end());
    cout << t << '\n';

    return 0;
}
