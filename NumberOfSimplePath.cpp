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
        ll n;
        cin >> n;
        vector<ll> adj[n + 1];
        vector<ll> c(n + 1, 0);
        vector<ll> d(n + 1, 1);
        for (ll i = 0; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            c[u]++;
            c[v]++;
        }
        queue<ll> q;
        for (ll i = 1; i <= n; i++)
        {
            if (c[i] == 1)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            c[u]--;
            ll v;
            for (auto x : adj[u])
            {
                if (c[x])
                {
                    v = x;
                    c[v]--;
                    break;
                }
            }
            d[v] += d[u];
            if (c[v] == 1)
            {
                q.push(v);
            }
        }
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            if (c[i])
            {
                res += (d[i] * (d[i] - 1)) / 2 + (n - d[i]) * d[i];
            }
        }
        cout << res << nl;
    }
    return 0;
}