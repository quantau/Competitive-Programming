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

set<ll> s;
ll dp[200001];
const ll mod = 1e9 + 7;

void solve(ll x)
{
    ll val = x;
    while (x)
    {
        if (s.find(x) != s.end())
            return;
        if (x % 2)
        {
            x = (x - 1) / 2;
        }
        else if (x % 4 == 0)
        {
            x /= 4;
        }
        else
        {
            break;
        }
    }
    s.insert(val);
}

int main()
{
    FASTIO

    ll n, p;
    cin >> n >> p;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (ll i = 0; i < n; i++)
    {
        solve(a[i]);
    }
    // dbg(s.size());
    for (auto x : s)
    {
        dp[msb(x)]++;
    }
    dp[1] += dp[0];
    for (ll i = 2; i < p; i++)
    {
        dp[i] += dp[i - 1] % mod;
        dp[i] %= mod;
        dp[i] += dp[i - 2] % mod;
        dp[i] %= mod;
    }
    ll res = 0;
    for (ll i = 0; i < p; i++)
    {
        // cout << dp[i] << " ";
        res += dp[i];
        res %= mod;
    }
    // cout << nl;
    cout << res << nl;
    return 0;
}