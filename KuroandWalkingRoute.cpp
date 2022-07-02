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

vector<ll> adj[300001];
bool val[300001];
ll c = 0;

void dfs(ll u, ll p, ll node)
{
    if (u == node)
    {
        val[u] = 1;
    }
    else
    {
        val[u] = val[p];
    }
    c += val[u];
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs(x, u, node);
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

    ll n, x, y;
    cin >> n >> x >> y;
    for (ll i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll res = 0;
    dfs(x, 0, y);
    res = -c;
    for (ll i = 1; i <= n; i++)
    {
        val[i] = 0;
    }
    c = 0;
    dfs(y, 0, x);
    res *= c;
    res += n * (n - 1);
    cout << res << nl;
    return 0;
}