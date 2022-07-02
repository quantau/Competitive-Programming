#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
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

    ll n, p, k;
    cin >> n >> p >> k;
    vector<pii> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].ff;
        v[i].ss = i;
    }
    ll s[n][p];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < p; j++)
        {
            cin >> s[i][j];
        }
    }
    ll sum = 0;
    sort(rall(v));
    for (ll i = 0; i < k; i++)
    {
        sum += v[i].ff;
    }
    ll dp[(1 << p)][n + 1];
    for (ll i = 0; i < (1 << p); i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (ll i = 0; i <= n; i++)
    {
        dp[0][i] = sum;
    }
    // dbg(sum);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < (1 << p); j++)
        {
            ll x = on_bit(j);
            for (ll l = 0; l < p; l++)
            {
                if (!(j & (1 << l)))
                {
                    // var(dp[j][i] + s[v[i].ss][l], (i - x < k ? v[k + x].ff - v[i].ff : 0), i, j);
                    dp[j | (1 << l)][i + 1] = max({dp[j | (1 << l)][i + 1], dp[j | (1 << l)][i], dp[j][i] + s[v[i].ss][l] + (i - x < k ? v[k + x].ff - v[i].ff : 0)});
                }
            }
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < (1 << p); j++)
    //     {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << nl;
    // }
    cout << dp[(1 << p) - 1][n] << nl;
    return 0;
}