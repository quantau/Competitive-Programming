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

ll dp[1005][1005];
const ll mod = 1e9 + 7;

int main()
{
    FASTIO

    ll h, w;
    cin >> h >> w;
    ll a[h][w];
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == '.' ? 1 : 0);
        }
    }
    dp[0][0] = 1;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (i && a[i - 1][j])
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
            if (j && a[i][j - 1])
            {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[h - 1][w - 1] << nl;
    return 0;
}