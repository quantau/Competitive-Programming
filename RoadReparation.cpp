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

ll inf = 1e15 + 1;
vector<pii> adj[100001];
bool vis[100001];
vector<ll> mn(100001, inf);

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    set<pii> q;
    q.insert({0, 1});
    mn[1] = 0;
    ll ans = 0;
    while (!q.empty())
    {
        ll u = (*q.begin()).ss;
        vis[u] = true;
        ans += (*q.begin()).ff;
        q.erase(q.begin());
        for (auto x : adj[u])
        {
            if (!vis[x.ss] && x.ff < mn[x.ss])
            {
                q.erase({mn[x.ss], x.ss});
                mn[x.ss] = x.ff;
                q.insert({x});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << ans << nl;
    return 0;
}