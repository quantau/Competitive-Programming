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

ll mod = 1e9 + 7;
vector<ll> adj[200001];
ll a[200001];
ll val[200001];
ll len[200001];
ll n;

void dfs1(ll u, ll p)
{
    len[u] = 1;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs1(x, u);
        len[u] += len[x];
        val[u] -= val[x];
    }
    val[u] += a[u] * len[u] % mod;
    val[u] %= mod;
}

void dfs2(ll u, ll p)
{
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        val[x] = -val[u] + ((n - len[x]) * a[x]) % mod + (len[x] * a[u]) % mod;
        val[x] %= mod;
        dfs2(x, u);
    }
}

int main()
{
    FASTIO
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << val[i] << " ";
    // }
    // cout << nl;
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res += val[i] % mod;
        res %= mod;
    }
    cout << (mod + res) % mod << endl;
    return 0;
}