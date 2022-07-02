#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << nl;
#define var(x, y, z) cout << x << " " << y << " " << z << nl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MAXN = 1e5 + 1;
vector<ll> adj[MAXN];
int vis[MAXN];

void dfs(ll node, ll component)
{
    vis[node] = component;
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            dfs(x, component);
        }
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

    const ll M = 1e9 + 7;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        ll componenets = 0;
        vector<ll> v(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            //var(i, vis[i], 0);
            if (!vis[i])
            {
                componenets++;
                dfs(i, componenets);
            }
            //var(i, vis[i], 0);
            //dbg(1);
            v[vis[i]]++;
        }
        // for (ll i = 1; i < n; i++)
        //     cout << v[i];
        // cout << nl;
        ll res = 1;
        for (ll i = 1; i <= n; i++)
        {
            (res *= (v[i] ? v[i] : 1)) %= M;
        }
        cout << componenets << " " << res << nl;
    }
    return 0;
}