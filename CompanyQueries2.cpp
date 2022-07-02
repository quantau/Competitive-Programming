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
ll lca[200001][21];
ll level[200001];

void dfs(ll u, ll p)
{
    lca[u][0] = p;
    level[u] = level[p] + 1;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs(x, u);
    }
}

ll loca(ll a, ll b)
{
    if (level[a] > level[b])
        swap(a, b);
    ll d = level[b] - level[a];
    while (d)
    {
        ll i = log2(d);
        b = lca[b][i];
        d -= (1 << i);
    }
    if (a == b)
        return b;
    for (ll i = 20; i >= 0; i--)
    {
        if (lca[a][i] && (lca[a][i] != lca[b][i]))
        {
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return lca[a][0];
}

void init(ll n)
{
    dfs(1, 0);
    for (ll j = 1; j <= 20; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            ll par = lca[i][j - 1];
            lca[i][j] = lca[par][j - 1];
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

    ll n, q;
    cin >> n >> q;
    for (ll i = 2; i <= n; i++)
    {
        ll v;
        cin >> v;
        adj[v].pb(i);
        adj[i].pb(v);
    }
    init(n);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = loca(a, b);
        cout << (ans ? ans : -1) << nl;
    }
    return 0;
}