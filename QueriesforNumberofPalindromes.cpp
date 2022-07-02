#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

ll dp[5005][5005];
bool is_pal[5005][5005];

int main()
{
    FASTIO

    string s;
    cin >> s;
    ll n = s.size();
    for (ll i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        is_pal[i][i] = 1;
        if (i)
        {
            dp[i - 1][i] = 2 + (s[i - 1] == s[i]);
            is_pal[i - 1][i] = (s[i - 1] == s[i]);
        }
    }

    for (ll i = 3; i <= n; i++)
    {
        for (ll j = 0; j + i - 1 < n; j++)
        {
            ll l = j, r = j + i - 1;
            is_pal[l][r] = (s[l] == s[r]) * is_pal[l + 1][r - 1];
            dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1] + is_pal[l][r];
            // cout << dp[l][r] << " ";
        }
        cout << nl;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp[l][r] << nl;
    }
    return 0;
}