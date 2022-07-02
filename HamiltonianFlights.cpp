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
    // freopen("output.txt", "w", stdout);

using namespace std;

ll a[25][25];
const ll mod = 1e9 + 7;
ll dp[(1 << 22)][22];

int main()
{
    FASTIO
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        a[u][v]++;
    }
    if (n == 2)
    {
        cout << a[0][n - 1] << nl;
        return 0;
    }
    n -= 2;
    for (ll i = 0; i < n; i++)
    {
        dp[1 << i][i] = a[0][i + 1];
    }

    for (ll i = 1; i < (1 << n); i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll l = 0; l < n; l++)
            {
                if (!(i & (1 << l)) && a[j + 1][l + 1])
                {
                    dp[i | (1 << l)][l] += dp[i][j] * a[j + 1][l + 1];
                    dp[i | (1 << l)][l] %= mod;
                }
            }
        }
    }
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!a[i + 1][n + 1])
            continue;
        res += dp[(1 << n) - 1][i] * a[i + 1][n + 1];
        res %= mod;
    }
    cout << res << nl;
    return 0;
}