#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, x;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
    }
    cin >> m;
    vector<int> b(m + 1, 0);
    for (int j = 1; j <= m; ++j) {
        cin >> x;
        b[j] = x;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i][j - 1] > dp[i - 1][j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    vector<int> ans;
    int i = n, j = m;
    while (dp[i][j] > 0){
        if (dp[i][j - 1] == dp[i][j]){
            j--;
        }
        else if (dp[i - 1][j] == dp[i][j]){
            i--;
        }
        else{
            ans.push_back(a[i]);
            i--;
            j--;
        }
    }
    cout << dp[n][m] << "\n";
    for (int t = dp[n][m] - 1; t >= 0; t--){
        cout << ans[t] << " ";
    }
    return 0;
}