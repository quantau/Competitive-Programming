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

vector<ll> adj[200001];
ll len[200001];
ll len_sum[200001];
ll ans[200001];
ll n;

void dfs1(ll u, ll p)
{
    len[u] = 1;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs1(x, u);
        len_sum[u] += len_sum[x];
        len[u] += len[x];
    }
    len_sum[u] += len[u];
}

void dfs2(ll u, ll p)
{
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        len_sum[x] = len_sum[u] - 2 * len[x] + n;
        dfs2(x, u);
    }
}

int main()
{
    FASTIO
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res = max(res, len_sum[i]);
    }
    cout << res << nl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << len[i] << " ";
    // }
    // cout << nl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << len_sum[i] << " ";
    // }
    // cout << nl;
    return 0;
}