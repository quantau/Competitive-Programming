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

vector<ll> adj[300005];
ll col[300005];
ll len[300005];
vector<ll> op;

void dfs(ll u, ll p)
{
    len[u]++;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs(x, u);
        len[u] += len[x];
    }
}

void make_equal(ll u, ll p, ll c)
{
    if (col[u] != c)
    {
        op.pb(u);
        c = (c == 0 ? 1 : 0);
    }
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        make_equal(x, u, c);
    }
}

void solve(ll u, ll p, ll r)
{
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        if (len[x] <= r)
        {
            op.pb(x);
            r -= len[x];
        }
        else
        {
            solve(x, u, r);
            break;
        }
    }
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        op.clear();
        for (ll i = 0; i <= n; i++)
        {
            adj[i].clear();
            len[i] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> col[i];
        }
        for (ll i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 0);
        make_equal(1, 0, 1);
        solve(1, 0, n / 2);
        cout << op.size() << nl;
        for (auto x : op)
        {
            cout << x << " ";
        }
        cout << nl;
    }
    return 0;
}