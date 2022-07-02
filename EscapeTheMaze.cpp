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

ll inf = 1e9 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> d(n + 1, inf);
    queue<ll> q;
    for (ll i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        q.push(x);
        d[x] = 0;
    }
    vector<ll> adj[n + 1];
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (d[x] > d[u] + 1)
            {
                d[x] = d[u] + 1;
                q.push(x);
            }
        }
    }
    vector<ll> d2(n + 1, inf);
    d2[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (d2[x] > d2[u] + 1 && d2[u] + 1 < d[x])
            {
                d2[x] = d2[u] + 1;
                q.push(x);
            }
        }
    }
    bool poss = false;
    for (ll i = 2; i <= n; i++)
    {
        if (d2[i] < inf && adj[i].size() == 1)
        {
            poss = true;
        }
    }
    if (poss)
    {
        cout << -1 << nl;
        return;
    }
    q.push(1);
    vector<ll> vis(n + 1, 0);
    ll ans = 0;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto x : adj[u])
        {
            if (vis[x])
                continue;
            if (d[x] <= d2[x])
            {
                ans++;
            }
            else
            {
                q.push(x);
            }
        }
    }
    cout << ans << nl;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}