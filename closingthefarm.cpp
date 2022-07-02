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
#define FREOPEN                        \
    freopen("closing.in", "r", stdin); \
    freopen("closing.out", "w", stdout);

using namespace std;

vector<ll> adj[200005];
ll p[200005];
ll len[200005];

ll get(ll x)
{
    if (p[x] == x)
        return x;
    p[x] = get(p[x]);
    return p[x];
}

void union_dsu(ll x, ll y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (len[x] < len[y])
        swap(x, y);
    p[y] = x;
    len[x] += len[y];
}

int main()
{
    FASTIO
    FREOPEN
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        len[i + 1] = 1;
        p[i + 1] = i + 1;
    }
    reverse(all(v));
    vector<bool> res;
    ll prev = v[0];
    bool vis[n + 1] = {0};
    vector<ll> nodes;
    for (ll i = 0; i < n; i++)
    {
        vis[v[i]] = 1;
        for (auto x : adj[v[i]])
        {
            if (vis[x])
                union_dsu(x, v[i]);
        }
        bool b = true;
        while (!nodes.empty())
        {
            if (get(nodes.back()) == get(v[i]))
            {
                nodes.pop_back();
            }
            else
            {
                b = false;
                break;
            }
        }
        nodes.pb(v[i]);
        res.pb(b);
    }
    reverse(all(res));
    for (auto x : res)
    {
        cout << (x ? "YES\n" : "NO\n");
    }
    return 0;
}