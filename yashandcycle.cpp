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

vector<ll> adj[100001];
ll col[100001];
bool vis[100001];
bool chk = true;
ll c[2] = {0};

void dfs(ll u, ll p)
{
    vis[u] = true;
    col[u] = p;
    c[(p + 1) / 2]++;
    for (auto x : adj[u])
    {
        if (col[x] == p)
        {
            chk = false;
            return;
        }
        if (vis[x])
            continue;
        dfs(x, -p);
    }
}

int main()
{
    FASTIO

    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll res = 0;
    bool chk2 = false;
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i, 1);
        if (!chk)
        {
            cout << 0 << " " << 1 << nl;
            return 0;
        }
        if (c[0] + c[1] >= 2)
        {
            res += (c[0] * (c[0] - 1)) / 2 + (c[1] * (c[1] - 1)) / 2;
            chk2 = true;
        }
        c[0] = 0, c[1] = 0;
    }
    if (res)
    {
        cout << 1 << " " << res << nl;
    }
    else if (chk2)
    {
        cout << 2 << " " << m * (n - 2) << nl;
    }
    else
    {
        cout << 3 << " " << (n * (n - 1) * (n - 2)) / 6 << nl;
    }
    return 0;
}