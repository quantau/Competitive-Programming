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

ll binpow(ll a, ll b, const ll MOD)
{
    a = a % MOD;
    if (a == 0)
        return 0;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res % MOD) * (a % MOD);
            res %= MOD;
        }
        a %= MOD;
        a = (a % MOD) * (a % MOD);
        a %= MOD;
        b >>= 1;
    }
    return res % MOD;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x = 0;
        for (ll i = 0; i < m; i++)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            x = (x | val);
        }
        ll val = binpow(2, n - 1, mod);
        val %= mod;
        val *= x;
        val %= mod;
        cout << val << endl;
    }
    return 0;
}