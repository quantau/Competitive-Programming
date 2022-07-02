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

ll mod = 1e9 + 7;
vector<ll> adj[200001];
ll vis[200001];
bool vis2[200001];

void dfs(ll u, ll n)
{
    vis2[u] = true;
    for (auto v : adj[u])
    {
        if (vis2[v])
        {
            vis[u] += vis[v] % mod;
            vis[u] %= mod;
            continue;
        }
        if (v == n)
        {
            vis[u] += 1;
            vis[u] %= mod;
            continue;
        }
        dfs(v, n);
        vis[u] += vis[v];
        vis[u] %= mod;
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

    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    dfs(1, n);
    cout << vis[1] % mod << nl;
    return 0;
}