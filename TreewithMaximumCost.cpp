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
ll suma[200001];
ll subtreeval[200001];
ll ans[200001];
ll a[200001];

void dfs1(ll u, ll p)
{
    suma[u] += a[u];
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs1(x, u);
        subtreeval[u] += subtreeval[x] + suma[x];
        suma[u] += suma[x];
    }
}

void dfs2(ll u, ll p)
{
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        ans[x] = ans[u] + suma[1] - 2 * suma[x];

        dfs2(x, u);
    }
}

int main()
{
    FASTIO
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        // dbg(1);
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        // dbg(2);
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 0);
    ans[1] = subtreeval[1];
    dfs2(1, 0);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << suma[i] << " ";
    // }
    // cout << nl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << subtreeval[i] << " ";
    // }
    // cout << nl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << nl;
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res = max(res, ans[i]);
    }
    cout << res << endl;
    return 0;
}