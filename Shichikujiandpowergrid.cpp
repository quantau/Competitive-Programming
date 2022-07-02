#include <bits/stdc++.h>
#define ll long long int
#define pii pair<ll, ll>

using namespace std;

ll p[2005];
ll len[2005];

ll get(ll x)
{
    if (p[x] == x)
        return x;
    p[x] = get(p[x]);
    return p[x];
}

void union_dsu(ll x, ll y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (len[x] < len[y])
        swap(x, y);
    len[x] += len[y];
    p[y] = x;
}

int main()
{
    ll n;
    cin >> n;
    for (ll i = 0; i <= n; i++)
    {
        p[i] = i;
        len[i] = 1;
    }
    ll x[n], y[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    ll c[n], k[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    vector<pair<ll, pii>> edges;
    for (ll i = 0; i < n; i++)
    {
        edges.push_back({c[i], {i, n}});
        for (ll j = i + 1; j < n; j++)
        {
            ll w = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.push_back({w, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    ll res = 0;
    vector<pii> p;
    vector<ll> src;
    for (auto x : edges)
    {
        ll w = x.first, u = x.second.first, v = x.second.second;
        if (get(u) != get(v))
        {
            if (u == n || v == n)
            {
                src.push_back(min(u, v));
            }
            else
            {
                p.push_back({u, v});
            }
            union_dsu(u, v);
            res += w;
        }
    }
    cout << res << "\n";
    cout << src.size() << "\n";
    for (auto x : src)
    {
        cout << x + 1 << " ";
    }
    cout << "\n";
    cout << p.size() << "\n";
    for (auto x : p)
    {
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    }
    return 0;
}