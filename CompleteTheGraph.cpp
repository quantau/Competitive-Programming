#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

ll inf = 1e18, one = 1;
vector<pii> adj[1001];
vector<pii> edges;
ll a[1001][1001];
ll d1[1001], d2[1001];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges.pb({u, v});
    }

    for (ll i = 0; i < n; i++)
    {
        d1[i] = inf;
        d2[i] = inf;
    }

    priority_queue<pii> q;
    q.push({0, t});
    d1[t] = 0;
    while (!q.empty())
    {
        ll u = q.top().ss;
        ll dis = -q.top().ff;
        q.pop();
        if (d1[u] != dis)
            continue;
        for (auto x : adj[u])
        {
            ll w = x.ss;
            if (!x.ss)
                w = 1;
            if (d1[x.ff] > dis + w)
            {
                d1[x.ff] = dis + w;
                q.push({-d1[x.ff], x.ff});
            }
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << d1[i] << " ";
    // }
    // cout << nl;

    q.push({0, s});
    d2[s] = 0;
    while (!q.empty())
    {
        ll u = q.top().ss;
        ll dis = -q.top().ff;
        q.pop();
        if (d2[u] != dis)
            continue;
        for (auto x : adj[u])
        {
            ll w = a[u][x.ff];
            //var(u, w, d1[x.ff], d2[u]);
            if (!w)
            {
                w = max(one, l - d1[x.ff] - d2[u]);
                //dbg(w);
                a[u][x.ff] = w;
                a[x.ff][u] = w;
            }
            if (d2[x.ff] > dis + w)
            {
                d2[x.ff] = dis + w;
                q.push({-d2[x.ff], x.ff});
            }
        }
    }

    if (d2[t] == l)
    {
        cout << "YES\n";
        for (ll i = 0; i < m; i++)
        {
            cout << edges[i].ff << " " << edges[i].ss << " " << a[edges[i].ff][edges[i].ss] << nl;
        }
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}