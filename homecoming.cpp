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

    ll inf = 1e14;
    ll n, m;
    cin >> n >> m;
    vector<pii> v[n + 1];
    map<pii, ll> mp;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        if (x == y)
            continue;
        if (mp.count({x, y}))
        {
            mp[{x, y}] = min(mp[{x, y}], w);
        }
        else
        {
            mp[{x, y}] = w;
        }
    }

    for (auto node : mp)
    {
        ll x = node.ff.ff;
        ll y = node.ff.ss;
        ll w = node.ss;
        v[x].pb({y, w});
        v[y].pb({x, w});
    }

    vector<pii> d(n + 1, {inf, inf});
    d[1] = {0, 0};
    queue<pair<ll, pii>> q;
    q.push({0, {1, 0}});
    while (!q.empty())
    {
        pair<ll, pii> p = q.front();
        q.pop();
        ll dis = p.ff;
        ll in = p.ss.ff;
        ll node = p.ss.ss;
        for (auto x : v[in])
        {
            if (d[x.ff].ff > dis + x.ss * (node + 1))
            {
                d[x.ff] = {dis + x.ss * (node + 1), node + 1};
                q.push({dis + x.ss * (node + 1), {x.ff, node + 1}});
            }
            else if (d[x.ff].ss > node + 1)
            {
                q.push({dis + x.ss * (node + 1), {x.ff, node + 1}});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << (d[i].ff == inf ? -1 : d[i].ff) << nl;
    }
    return 0;
}