#include <bits/stdc++.h>

using namespace std;

int bin_search(vector<pair<int, int>> mas, int x){
    int l = -1, r = mas.size(), m;
    while (r - l > 1){
        m = (r + l) / 2;
        if (mas[m].first < x){
            l = m;
        }
        else{
            r = m;
        }
    }
    return r;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x, ind, ans = 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> x;
        a[i] = x;
    }
    vector<pair<int, int>> dp;
    dp.emplace_back(a[0], 0);
    vector<int> pr(n, -1);
    for (int i = 1; i < n; ++i){
        if (a[i] > dp[ans - 1].first){
            dp.emplace_back(a[i], i);
            ind = ans;
            ans++;
        }
        else{
            ind = bin_search(dp, a[i]);
            dp[ind] = make_pair(a[i], i);
        }
        if (ind > 0){
            pr[i] = dp[ind - 1].second;
        }
    }
    int i = dp[ans - 1].second;
    vector<int> wr;
    while (pr[i] != -1){
        wr.push_back(a[i]);
        i = pr[i];
    }
    wr.push_back(a[i]);
    cout << ans << "\n";
//    for (int i = ans - 1; i >= 0; --i){
//        cout << wr[i] << " ";
//    }
    return 0;
}