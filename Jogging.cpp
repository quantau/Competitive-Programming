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
vector<pii> adj[100001];
ll d[100001];
// ll p[100001];
bool vis[100001];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    for (ll i = 0; i < n; i++)
    {
        d[i] = inf;
        // p[i] = -1;
    }
    d[0] = 0;
    ll res = 0;
    priority_queue<pii> q;
    q.push({0, 0});
    while (!q.empty())
    {
        ll u = q.top().ss;
        ll dis = -q.top().ff;
        q.pop();
        vis[u] = true;
        if (dis != d[u])
            continue;
        for (auto x : adj[u])
        {
            if (vis[x.ff])
                continue;
            res++;
            if (d[x.ff] > dis + x.ss)
            {
                d[x.ff] = dis + x.ss;
                if (2 * d[x.ff] < r)
                {
                    q.push({-d[x.ff], x.ff});
                }
            }
        }
    }
    cout << res << nl;
    return 0;
}

// 4 4 80 90
// 0 1 40
// 0 2 50
// 1 2 30
// 2 3 10
