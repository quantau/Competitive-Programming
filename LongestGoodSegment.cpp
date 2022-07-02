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

vector<ll> adj[100005];
ll lca[100005][31];
ll length[100005];

void dfs(ll u, ll p)
{
    length[u] = length[p] + 1;
    lca[u][0] = p;
    for (auto x : adj[u])
    {
        if (x == p)
            continue;
        dfs(x, u);
    }
}

void init(ll n)
{
    for (ll i = 0; i <= n + 1; i++)
    {
        length[i] = -1;
    }
    for (ll i = n + 1; i >= 1; i--)
    {
        if (length[i] < 0)
        {
            dfs(i, 0);
        }
    }
    for (ll j = 1; j <= 30; j++)
    {
        for (ll i = 1; i <= n; i++)
        {
            ll par = lca[i][j - 1];
            lca[i][j] = lca[par][j - 1];
        }
    }
}

ll getLift(ll a, ll d)
{
    while (d)
    {
        ll i = log2(d);
        a = lca[a][i];
        d -= (1 << i);
    }
    return a;
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
        ll n, k, s;
        cin >> n >> k >> s;
        for (ll i = 0; i <= n + 1; i++)
        {
            adj[i].clear();
            length[i] = -1;
            for (ll j = 0; j <= 30; j++)
            {
                lca[i][j] = 0;
            }
        }
        ll a[n + 5];
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<ll> v(n + 1, 0);
        v[1] = a[1];
        for (ll i = 2; i <= n; i++)
        {
            v[i] = a[i] + v[i - 1];
        }
        sort(all(v));
        ll sum = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll j = upper_bound(all(v), sum + s) - v.begin();
            if (i == j)
                continue;
            adj[i].pb(j);
            adj[j].pb(i);
            sum += a[i];
        }
        init(n);
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll dis = min(length[i], k);
            ll j = getLift(i, dis);
            res = max(res, j - i);
        }
        cout << res << nl;
    }
    return 0;
}