#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a1, b1, c1;
    cin >> n;
    vector<int> a(n), b(n), c(n), dp(n);
    for (int i = 0; i < n; ++i) {
        cin >> a1 >> b1 >> c1;
        a[i] = a1;
        b[i] = b1;
        c[i] = c1;
        if (i == 0) dp[0] = a[0];
        else if (i == 1) dp[1] = min(a[0] + a[1], b[0]);
        else if (i == 2) {
            dp[2] = min(dp[1] + a[2], a[0] + b[1]);
            dp[2] = min(dp[2], c[0]);
        } else {
            dp[i] = min(a[i] + dp[i - 1], b[i - 1] + dp[i - 2]);
            dp[i] = min(dp[i], c[i - 2] + dp[i - 3]);
        }
    }
    cout << dp[n - 1];
    return 0;
}