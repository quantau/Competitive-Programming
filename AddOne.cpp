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
const ll MAXN = 2 * 1e5 + 5;

ll dp[MAXN + 20][10];

void pre()
{
    dp[0][0] = 1;
    for (ll i = 1; i <= MAXN + 10; i++)
    {
        for (ll j = 0; j < 9; j++)
        {
            dp[i][j + 1] += dp[i - 1][j] % mod;
            dp[i][j + 1] %= mod;
        }
        dp[i][0] += dp[i - 1][9] % mod;
        dp[i][1] += dp[i - 1][9] % mod;
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
}

int main()
{
    FASTIO
    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        ll m;
        cin >> s >> m;
        ll res = 0;
        for (auto x : s)
        {
            ll moves = m + (x - '0');
            for (ll i = 0; i < 10; i++)
            {
                res += dp[moves][i];
                res %= mod;
            }
        }
        cout << res << nl;
    }
    return 0;
}