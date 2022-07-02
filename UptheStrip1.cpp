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

    double ep = 1e-20;
    ll n, m;
    cin >> n >> m;
    ll dp[n + 1];
    dp[1] = 1;
    ll sum = dp[1];
    for (ll i = 2; i <= n; i++)
    {
        dp[i] = sum;
        double sq = sqrt(i);
        for (ll j = 2; j * j < i; j++)
        {
            if (sq - (i / j) > ep)
                continue;
            dp[i] += dp[i / j] % m;
            dp[i] %= m;
        }
        for (ll j = 1; j * j <= i; j++)
        {
            ll len = (i / j) - (i / (j + 1));
            dp[i] += (len * dp[j]) % m;
            dp[i] %= m;
        }
        sum += dp[i];
        sum %= m;
    }
    // for (ll i = 1; i < n; i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << nl;
    cout << dp[n] % m << nl;
    return 0;
}