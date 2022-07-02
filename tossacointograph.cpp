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

const ll MAXN = 200005;
vector<ll> adj[MAXN];
ll a[MAXN];
ll len[MAXN];
ll n, m, k;
ll vis[MAXN];
bool leff[MAXN];

void dfs(ll u, ll z, ll p)
{
    vis[u] = p;
    len[u] = 1;
    ll mx = 0;
    for (auto x : adj[u])
    {
        if (a[x] > z)
            continue;
        if (vis[x] == p && !leff[x])
        {
            len[x] = k;
            return;
        }
        else if (!vis[x])
        {
            dfs(x, z, p);
        }
        mx = max(mx, len[x]);
    }
    len[u] = min(k, len[u] + mx);
    leff[u] = true;
}

bool ok(ll x)
{
    for (ll i = 0; i <= n; i++)
    {
        vis[i] = 0;
        len[i] = 0;
        leff[i] = 0;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] || a[i] > x)
            continue;
        dfs(i, x, i);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (len[i] >= k && a[i] <= x)
            return true;
    }
    return false;
}

int main()
{
    FASTIO

    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    ll lo = 1, hi = 1e9 + 1;
    ll res = hi + 5;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        // var(lo, mid, hi);
        if (ok(mid))
        {
            res = min(res, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    // ok(3);
    cout << (res >= 1e9 + 3 ? -1 : res) << nl;
    return 0;
}