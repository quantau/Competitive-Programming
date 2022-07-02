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
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    ll sum = 1, div = 0;
    for (ll i = 2; i <= n; i++)
    {
        dp[i] += sum;
        dp[i] %= m;
        dp[i] += div;
        dp[i] %= m;
        dp[i]++;
        div = (m + dp[i] - sum) % m;
        sum += dp[i];
        sum %= m;
        for (ll j = 2 * i; j <= n; j += i)
        {
            dp[j] += (m + dp[i] - dp[i - 1]) % m;
            dp[j] %= m;
        }
    }
    cout << dp[n] % m << nl;
    return 0;
}