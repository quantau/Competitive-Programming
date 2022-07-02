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

ll vis[300005][2];
vector<ll> adj[300005][2];
ll len[300005];

void dfs(ll u, ll p, ll par)
{
    // var(u, p, par);
    vis[u][p] = par + 1;
    len[par]++;
    for (auto x : adj[u][p])
    {
        if (vis[x][!p])
            continue;
        dfs(x, !p, par);
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
        string s;
        cin >> s;
        for (ll i = 0; i <= n; i++)
        {
            vis[i][0] = 0;
            vis[i][1] = 0;
            adj[i][0].clear();
            adj[i][1].clear();
            len[i] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'L')
            {
                adj[i][0].pb(i - 1);
                adj[i - 1][1].pb(i);
            }
            else
            {
                adj[i][1].pb(i - 1);
                adj[i - 1][0].pb(i);
            }
        }
        for (ll i = 0; i <= n; i++)
        {
            if (vis[i][0])
                continue;
            dfs(i, 0, i);
        }
        for (ll i = 0; i <= n; i++)
        {
            cout << len[vis[i][0] - 1] << " ";
        }
        cout << nl;
    }
    return 0;
}