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

ll inf = 1e17;
vector<ll> adj[1001];
ll d[1001], p[1001];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    set<pair<ll, pii>> s;
    for (ll i = 0; i < k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        s.insert({a, {b, c}});
    }
    for (ll i = 1; i <= n; i++)
    {
        d[i] = inf;
        p[i] = -1;
    }
    queue<ll> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto x : adj[u])
        {
            if (s.find({p[u], {u, x}}) != s.end())
                continue;
            if (d[x] > d[u] + 1)
            {
                d[x] = d[u] + 1;
                p[x] = u;
                q.push(x);
            }
        }
    }
    if (d[n] == inf)
    {
        cout << -1 << nl;
    }
    else
    {
        cout << d[n] << nl;
        ll scr = n;
        vector<ll> v;
        v.pb(n);
        while (scr != 1)
        {
            scr = p[scr];
            v.pb(scr);
        }
        reverse(all(v));
        for (ll i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << nl;
    }
    return 0;
}