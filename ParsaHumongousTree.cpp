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

vector<ll> adj[100005];
ll l[100005][2];
ll dp[100005][2];

void dfs(ll u, ll p)
{
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs(x, u);
        dp[u][0] += max(dp[x][0] + abs(l[x][0] - l[u][0]), dp[x][1] + abs(l[x][1] - l[u][0]));
        dp[u][1] += max(dp[x][0] + abs(l[x][0] - l[u][1]), dp[x][1] + abs(l[x][1] - l[u][1]));
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
        for (ll i = 0; i <= n; i++)
        {
            adj[i].clear();
            l[i][0] = 0, l[i][1] = 0, dp[i][0] = 0, dp[i][1] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> l[i][0] >> l[i][1];
        }
        for (ll i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << nl;
    }
    return 0;
}