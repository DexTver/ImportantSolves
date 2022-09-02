#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> hp, rev_hp, level_t;  // хеш-префиксы строки, хеш-префиксы перевёрнутой строки, степени t
ll n, t = 113, R = 1000000021;

bool is_palindrome(ll l, ll r) {  // [l + 1, r]
    ll h, re_h;  // хеш подстроки, хэш перевёрнутой строки
    h = hp[r] - (hp[l] * level_t[r - l]) % R;
    h = (h + R) % R; // для исключения отрицательного значения
    re_h = rev_hp[n - l] - (rev_hp[n - r] * level_t[r - l]) % R;
    re_h = (re_h + R) % R;
    return h == re_h;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll q;
    cin >> q;
    while (q--) {
        string s, rev_s;
        cin >> s;
        rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        n = (ll) s.length();

        hp.assign(n + 1, 0);
        rev_hp.assign(n + 1, 0);
        level_t.assign(n + 1, 0);
        level_t[0] = 1;
        for (ll i = 1; i <= n; i++) {
            level_t[i] = (level_t[i - 1] * t) % R;
            hp[i] = (hp[i - 1] * t + s[i - 1]) % R;
            rev_hp[i] = (rev_hp[i - 1] * t + rev_s[i - 1]) % R;
        }

        ll r = n - 1, l = 0;
        while (s[l] == s[r] && r > l) {
            r--;
            l++;
        }
        if (r - l <= 0) {
            cout << s << "\n";
            continue;
        }

        ll m, m1;
        m = r;
        while (m >= l) {
            if (is_palindrome(l, m + 1)) break;
            m--;
        }
        m1 = l;
        while (m1 <= r) {
            if (is_palindrome(m1, r + 1)) break;
            m1++;
        }
        if (m - l > r - m1) {
            for (ll i = 0; i <= m; i++) cout << s[i];
            for (ll i = r + 1; i < n; i++) cout << s[i];
            cout << "\n";
        } else {
            for (ll i = 0; i < l; i++) cout << s[i];
            for (ll i = m1; i < n; i++) cout << s[i];
            cout << "\n";
        }
    }
    return 0;
}