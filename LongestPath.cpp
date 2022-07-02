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

vector<ll> adj[100005];
ll indegree[100005];
ll vis[100005];
ll dp[100005];

void dfs(ll u, ll p)
{
    dp[u] = max(dp[u], dp[p] + 1);
    if (vis[u] != indegree[u])
        return;
    for (auto x : adj[u])
    {
        vis[x]++;
        dfs(x, u);
    }
}

int main()
{
    FASTIO

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        indegree[v]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!indegree[i])
            dfs(i, 0);
    }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);
    }
    cout << res - 1 << nl;
    return 0;
}