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

using namespace std;

vector<ll> p(200001, -1);
vector<ll> adj[200001];
bool vis[200001];
ll c[200001];
ll res = 0;

ll get(ll x)
{
    if (p[x] < 0)
    {
        return x;
    }
    p[x] = get(p[x]);
    return p[x];
}

void union_dsu(ll x, ll y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (-p[x] < -p[y])
        swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

void dfs(ll u, ll p)
{
    vis[u] = true;
    c[u] = 1;
    for (auto x : adj[u])
    {
        if (vis[x])
            continue;
        dfs(x, u);
        c[u] += c[x];
    }
}

void dfs2(ll u, ll p, ll connect, ll mx)
{
    res += connect - mx;
    // var(connect - mx, u, mx);
    vis[u] = true;
    for (auto x : adj[u])
    {
        if (vis[x])
            continue;
        dfs2(x, u, connect, max(mx, c[x]));
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i <= n; i++)
        {
            p[i] = -1;
            adj[i].clear();
            c[i] = 0;
            vis[i] = false;
        }
        pii pn;
        for (ll i = 0; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            if (get(u) == get(v))
            {
                pn = {u, v};
            }
            else
            {
                union_dsu(u, v);
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        res = (n * (n - 1)) / 2;
        vis[pn.ss] = true;
        dfs(pn.ff, 0);
        for (ll i = 0; i <= n; i++)
        {
            vis[i] = false;
            // c[i] = 0;
        }
        vis[pn.ff] = true;
        // dbg(c[pn.ff]);
        dfs2(pn.ss, 0, c[pn.ff], 0);
        cout << res << nl;
    }
    return 0;
}