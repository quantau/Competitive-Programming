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

ll MOD = 1e9 + 7;

ll power(ll x, ll y, ll p = MOD)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n % 2)
        {
            ll val = power(2, n - 1) % MOD;
            val = power(val + 1, k) % MOD;
            cout << val << nl;
        }
        else
        {
            ll res = power(2, n - 1) % MOD;
            res = power(res - 1, k) % MOD;
            ll num = power(2, n - 1);
            for (ll i = 0; i < k; i++)
            {
                ll implicant = power(2, n * i);
                implicant %= MOD;
                implicant *= power(num - 1, k - 1 - i);
                implicant %= MOD;
                res += implicant;
                res %= MOD;
            }
            cout << res << nl;
        }
    }
    return 0;
}