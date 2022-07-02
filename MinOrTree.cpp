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

bool vis[200001];
vector<pii> adj[200001];

void dfs(ll u, ll bit)
{
    vis[u] = true;
    for (auto x : adj[u])
    {
        if (vis[x.ff] || (bit & x.ss))
            continue;
        dfs(x.ff, bit);
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
        ll n, m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
        for (ll i = 0; i < m; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        ll res = 0, useless = 0;
        for (ll i = 30; i >= 0; i--)
        {
            for (ll j = 1; j <= n; j++)
                vis[j] = 0;
            ll num = 1LL << i;
            // dbg(num);
            dfs(1, num + useless);
            bool b = true;
            for (ll j = 1; j <= n; j++)
            {
                if (!vis[j])
                {
                    // dbg(j);
                    res += (num);
                    b = false;
                    break;
                }
            }
            if (b)
            {
                useless += num;
            }
        }
        cout << res << nl;
    }
    return 0;
}