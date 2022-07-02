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

int main()
{
    FASTIO

    ll n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    string s[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    ll cost[n][6];
    for (ll j = 0; j < 6; j++)
    {
        for (ll i = 0; i < n; i++)
        {
            cost[i][j] = (str[i] == s[j][i % 3] ? 0 : 1);
        }
        for (ll i = 1; i < n; i++)
        {
            cost[i][j] += cost[i - 1][j];
        }
    }
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        if (l == 0)
        {
            ll res = n;
            for (ll i = 0; i < 6; i++)
            {
                res = min(res, cost[r][i]);
            }
            cout << res << nl;
        }
        else
        {
            ll res = n;
            for (ll i = 0; i < 6; i++)
            {
                res = min(res, cost[r][i] - cost[l - 1][i]);
            }
            cout << res << nl;
        }
    }
    return 0;
}