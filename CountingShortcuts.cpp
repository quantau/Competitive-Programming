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
ll paths[200001][2];
ll dis[200001];
ll mod = 1e9 + 7;
ll inf = 1e17;

void solve()
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    for (ll i = 0; i <= n; i++)
    {
        adj[i].clear();
        dis[i] = inf;
        paths[i][0] = 0;
        paths[i][1] = 0;
    }
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dis[s] = 0;
    paths[s][0] = 1;
    queue<ll> q;
    q.push(s);
    vector<ll> vis;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis.pb(u);
        for (auto x : adj[u])
        {
            if (dis[x] == inf)
            {
                dis[x] = dis[u] + 1;
                paths[x][0] = paths[u][0] % mod;
                paths[x][0] %= mod;
                q.push(x);
            }
            else if (dis[x] == dis[u] + 1)
            {
                paths[x][0] += paths[u][0] % mod;
                paths[x][0] %= mod;
            }
        }
    }
    for (auto u : vis)
    {
        for (auto x : adj[u])
        {
            if (dis[u] == dis[x])
            {
                paths[u][1] += paths[x][0] % mod;
                paths[u][1] %= mod;
            }
            if (dis[u] == dis[x] + 1)
            {
                paths[u][1] += paths[x][1] % mod;
                paths[u][1] %= mod;
            }
        }
    }
    // var(paths[t][0], paths[t][1], -1);
    cout << (paths[t][0] % mod + paths[t][1] % mod) % mod << nl;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}