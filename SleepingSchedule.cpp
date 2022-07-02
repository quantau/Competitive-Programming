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

ll n, h, l, r;
ll a[2002];
bool chk(ll i, ll j)
{
    ll hour = (a[i] - j) % h;
    if (hour >= l && hour <= r)
        return true;
    return false;
}

int main()
{
    FASTIO
    cin >> n >> h >> l >> r;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        a[i] += a[i - 1];
    }
    ll dp[n + 5][n + 5]; // max good sleeping time for i sleep cycles with j , -1 paths.
    for (ll i = 0; i <= n + 4; i++)
    {
        for (ll j = 0; j <= n + 4; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (ll i = 0; i <= n; i++) // number of times sleep cycle restored
    {
        for (ll j = 0; j <= i; j++) // number of times -1 path took
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + chk(i + 1, j));
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + chk(i + 1, j + 1));
        }
    }
    ll res = 0;
    for (ll i = 0; i <= n; i++)
    {
        res = max(res, dp[n][i]);
    }
    cout << res << nl;
    return 0;
}