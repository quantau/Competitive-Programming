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
#define pp pair<ll, pii>

using namespace std;

vector<pii> adj[100001];
ll d[100001][20];
ll inf = 1e17;

int main()
{
    FASTIO
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            d[i][j] = inf;
        }
    }
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for (ll i = 0; i <= k; i++)
    {
        d[1][i] = 0;
    }
    priority_queue<pp, vector<pp>, greater<pp>> q;
    q.push({0, {0, 1}});
    while (!q.empty())
    {
        ll u = q.top().ss.ss;
        ll dis = q.top().ff;
        ll j = q.top().ss.ff;
        q.pop();
        for (auto x : adj[u])
        {
            if (j < k && d[x.ff][j + 1] > d[u][j])
            {
                d[x.ff][j + 1] = d[u][j];
                q.push({d[x.ff][j + 1], {j + 1, x.ff}});
            }
            if (d[x.ff][j] > d[u][j] + x.ss)
            {
                d[x.ff][j] = d[u][j] + x.ss;
                q.push({d[x.ff][j], {j, x.ff}});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        ll ans = inf;
        for (ll j = 0; j <= k; j++)
        {
            ans = min(ans, d[i][j]);
        }
        cout << ans << " ";
    }
    cout << nl;
    return 0;
}