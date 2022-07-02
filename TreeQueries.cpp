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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

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
    FASTIO

    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    init(n);
    while (m--)
    {
        ll k;
        cin >> k;
        vector<pii> vec(k);
        for (ll i = 0; i < k; i++)
        {
            ll node;
            cin >> node;
            vec[i] = {level[node], node};
        }
        sort(rall(vec));
        bool b = true;
        for (ll i = 1; i < k; i++)
        {
            ll hlevel = min(vec[i].ff, vec[i - 1].ff);
            ll par = loca(vec[i].ss, vec[i - 1].ss);
            // var(vec[i].ff, vec[i - 1].ff, level[par]);
            if (hlevel - level[par] > 1)
            {
                cout << "NO\n";
                b = false;
                break;
            }
        }
        if (!b)
            continue;
        cout << "YES\n";
    }
    return 0;
}