
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

const ll mod = 998244353;

ll binpow(ll a, ll b)
{
    a = a % mod;
    if (a == 0)
        return 0;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res % mod) * (a % mod);
            res %= mod;
        }
        a %= mod;
        a = (a % mod) * (a % mod);
        a %= mod;
        b >>= 1;
    }
    return res % mod;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<bool> r(n + 5, 0), c(m + 5, 0);
        ll rcont = 0, ccont = 0;
        vector<pii> v(n);
        for (ll i = 0; i < q; i++)
        {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            v.pb({x, y});
        }
        reverse(all(v));
        ll cont = 0;
        for (ll i = 0; i < q; i++)
        {
            ll x = v[i].ff, y = v[i].ss;
            if (!r[x] || !c[y])
            {
                cont++;
            }
            if (!r[x])
            {
                r[x] = 1;
                rcont++;
            }
            if (!c[y])
            {
                c[y] = 1;
                ccont++;
            }
            if (rcont == n || ccont == m)
                break;
        }
        cout << binpow(k, cont) % mod << nl;
    }
    return 0;
}