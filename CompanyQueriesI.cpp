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

vector<ll> adj[200001];
ll lca[200001][25];
ll level[200001];

void dfs(ll u, ll p)
{
    lca[u][0] = p;
    level[u] = level[p] + 1;
    for (auto x : adj[u])
    {
        if (p == x)
            continue;
        dfs(x, u);
    }
}

ll loca(ll a, ll b)
{
    while (b)
    {
        ll i = log2(b);
        a = lca[a][i];
        b -= (1 << i);
    }
    return a;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i < n; i++)
    {
        ll u;
        cin >> u;
        adj[u].pb(i + 1);
        adj[i + 1].pb(u);
    }
    dfs(1, 0);
    for (ll i = 1; i <= 20; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (lca[j][i - 1])
            {
                ll par = lca[j][i - 1];
                lca[j][i] = lca[par][i - 1];
            }
        }
    }
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = loca(a, b);
        cout << (ans == 0 ? -1 : ans) << nl;
    }
    return 0;
}