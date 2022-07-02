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

ll solve(ll n, ll k)
{
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j] % mod;
                dp[i] %= mod;
            }
        }
    }
    // for (ll i = 0; i <= n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << nl;
    return dp[n];
}

int main()
{
    FASTIO

    ll n, k, d;
    cin >> n >> k >> d;
    ll res = (solve(n, k) - solve(n, d - 1) + mod) % mod;
    cout << res << nl;
    return 0;
}