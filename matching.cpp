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

const ll mod = 1e9 + 7;
ll dp[(1 << 21)];

int main()
{
    FASTIO

    ll n;
    cin >> n;
    ll a[n][n];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll x = on_bit(i);
        for (ll j = 0; j < n; j++)
        {
            if (!(i & (1 << j)) && a[j][x])
            {
                dp[i | (1 << j)] += dp[i];
                dp[i | (1 << j)] %= mod;
            }
        }
    }
    cout << dp[(1 << n) - 1] << nl;
    return 0;
}