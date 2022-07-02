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
ll rail[100001];
ll d[100001];
bool parity[100001];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k, res = 0;
    cin >> n >> m >> k;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for (ll i = 0; i < k; i++)
    {
        ll s, w;
        cin >> s >> w;
        if (rail[s])
        {
            res++;
            rail[s] = min(rail[s], w);
        }
        else
        {
            rail[s] = w;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    priority_queue<pii> q;
    for (ll i = 2; i <= n; i++)
    {
        if (rail[i])
        {
            d[i] = rail[i];
            parity[i] = 1;
            q.push({-rail[i], i});
        }
    }
    d[1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        ll u = q.top().ss;
        ll dis = -q.top().ff;
        q.pop();
        if (dis != d[u])
            continue;
        for (auto x : adj[u])
        {
            if (d[x.ff] > dis + x.ss)
            {
                parity[x.ff] = 0;
                d[x.ff] = dis + x.ss;
                q.push({-d[x.ff], x.ff});
            }
            else if (d[x.ff] == dis + x.ss && parity[x.ff])
            {
                parity[x.ff] = 0;
            }
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (rail[i] && !parity[i])
        {
            res++;
        }
    }
    cout << res << nl;
    return 0;
}