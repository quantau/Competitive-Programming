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
vector<ll> adj[2501];

void dfs(ll scr, vector<bool> &vis)
{
    vis[scr] = 1;
    for (auto x : adj[scr])
    {
        if (vis[x])
            continue;
        dfs(x, vis);
    }
}

bool solve(ll &res)
{
    ll inf = 1e17;
    ll n, m;
    cin >> n >> m;
    vector<pair<pii, ll>> v;
    for (ll i = 0; i < m; i++)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[a].pb(b);
        v.pb({{a, b}, -x});
    }
    ll d[n + 1];
    for (ll i = 0; i <= n; i++)
    {
        d[i] = inf;
    }
    d[1] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto x : v)
        {
            d[x.ff.ss] = min(d[x.ff.ss], d[x.ff.ff] + x.ss);
        }
    }
    res = d[n];
    for (auto x : v)
    {
        if (d[x.ff.ff] != inf && d[x.ff.ff] + x.ss < d[x.ff.ss])
        {
            vector<bool> vis(n + 1, 0);
            dfs(1, vis);
            if (vis[x.ff.ff])
            {
                for (ll i = 0; i <= n; i++)
                    vis[i] = 0;
                dfs(x.ff.ff, vis);
                if (vis[n])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll res = 0;
    if (solve(res))
    {
        cout << -res << nl;
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}