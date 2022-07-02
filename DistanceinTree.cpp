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

vector<ll> adj[50005];
ll dis[50005][505];
ll res = 0;
ll n, k;

void dfs1(ll u, ll p)
{
    dis[u][0] = 1;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs1(x, u);
        for (ll i = 1; i <= k; i++)
        {
            dis[u][i] += dis[x][i - 1];
        }
    }
}

void dfs2(ll u, ll p)
{
    // var(dis[u][k], dis[u][k - 1], dis[u][k - 2]);
    res += dis[u][k];
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        for (ll i = k; i >= 2; i--)
        {
            dis[x][i] += dis[u][i - 1] - dis[x][i - 2];
        }
        dis[x][1] += dis[u][0];
        dfs2(x, u);
    }
}

int main()
{
    FASTIO

    cin >> n >> k;
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(1, 0);
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 0; j <= k; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    dfs2(1, 0);
    cout << res / 2 << nl;
    return 0;
}

//efficient way to find gcd
ll get_gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return get_gcd(b, a % b);
    }
}