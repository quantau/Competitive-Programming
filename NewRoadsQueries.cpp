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

ll p[200001];
ll d[200001];
ll t[200001];

ll get_dsu(ll x)
{
    if (p[x] == x)
        return x;
    return get_dsu(p[x]);
}

void union_dsu(ll x, ll y, ll time)
{
    x = get_dsu(x);
    y = get_dsu(y);
    if (x == y)
        return;
    if (d[x] < d[y])
        swap(x, y);
    p[y] = x;
    d[x] += d[y];
    t[y] = time;
}

ll solve(ll x1, ll y1)
{
    ll x = x1, y = y1;
    vector<ll> v[2];
    while (p[x] != x)
    {
        //dbg(1);
        v[0].pb(x);
        x = p[x];
    }
    v[0].pb(x);
    while (p[y] != y)
    {
       // dbg(2);
        v[1].pb(y);
        y = p[y];
    }
    v[1].pb(y);
    ll parent = -1;
    for (ll i = 0; i < v[0].size(); i++)
    {
        for (ll j = 0; j < v[1].size(); j++)
        {
            if (v[0][i] == v[1][j])
            {
                parent = v[0][i];
                break;
            }
        }
        if (parent != -1)
            break;
    }
    while (p[x1] != parent)
    {
        x1 = p[x1];
    }
    while (p[y1] != parent)
    {
        y1 = p[y1];
    }
    return max(t[x1], t[y1]);
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, q;
    cin >> n >> m >> q;
    for (ll i = 1; i <= n; i++)
    {
        p[i] = i;
        d[i] = 0;
        t[i] = 0;
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        union_dsu(x, y, i + 1);
    }
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (get_dsu(x) == get_dsu(y))
        {
            cout << solve(x, y) << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}