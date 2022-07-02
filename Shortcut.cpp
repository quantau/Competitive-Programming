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

ll inf = 1e17;
vector<pii> adj[50001];
vector<ll> v[50001];
ll f[10001];
ll c[10001];
ll d[10001];
ll p[10001];

void dfs(ll node, ll par)
{
    f[node] = c[node];
    for (auto x : v[node])
    {
        if (x == par)
            continue;
        dfs(x, node);
        f[node] += f[x];
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);

    ll n, m, t;
    cin >> n >> m >> t;
    for (ll i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    for (ll i = 1; i <= n; i++)
    {
        d[i] = inf;
        p[i] = -1;
    }
    d[1] = 0;
    priority_queue<pii> q;
    q.push({0, -1});
    while (!q.empty())
    {
        ll u = -q.top().ss;
        ll dis = -q.top().ff;
        q.pop();
        if (dis != d[u])
            continue;
        for (auto x : adj[u])
        {
            if (d[x.ff] > dis + x.ss)
            {
                d[x.ff] = dis + x.ss;
                p[x.ff] = u;
                q.push({-d[x.ff], -x.ff});
            }
            else if (d[x.ff] == dis + x.ss && u < p[x.ff])
            {
                p[x.ff] = u;
                q.push({-d[x.ff], -x.ff});
            }
        }
    }
    ll ans = 0;
    for (ll i = 2; i <= n; i++)
    {
        v[i].pb(p[i]);
        v[p[i]].pb(i);
        //cout << p[i] << " ";
    }
    // cout << nl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << nl;
    dfs(1, -1);

    for (ll i = 2; i <= n; i++)
    {
        ans = max(ans, f[i] * (d[i] - t));
    }
    cout << ans;
    return 0;
}