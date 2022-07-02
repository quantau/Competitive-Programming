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

ll inf = 1e11;
vector<ll> adj[40001];
vector<ll> db(40001, inf), dg(40001, inf), dn(40001, inf);

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c[3], n, m;
    cin >> c[0] >> c[1] >> c[2] >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<ll> q;
    db[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (db[x] > db[u] + 1)
            {
                db[x] = db[u] + 1;
                q.push(x);
            }
        }
    }

    dg[2] = 0;
    q.push(2);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (dg[x] > dg[u] + 1)
            {
                dg[x] = dg[u] + 1;
                q.push(x);
            }
        }
    }

    dn[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (dn[x] > dn[u] + 1)
            {
                dn[x] = dn[u] + 1;
                q.push(x);
            }
        }
    }

    ll ans = c[0] * db[n] + c[1] * dg[n];
    for (ll i = 1; i <= n; i++)
    {
        ans = min(ans, c[0] * db[i] + c[1] * dg[i] + c[2] * dn[i]);
    }
    cout << ans << nl;
    return 0;
}