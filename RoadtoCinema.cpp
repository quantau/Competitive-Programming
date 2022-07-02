
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

vector<pii> v;
ll n, k, s, tim;
ll zero = 0;
vector<ll> g;

bool ok(ll in)
{
    ll gas = v[in].ss;
    ll loc = 0;
    ll t = 0;
    // dbg(gas);
    for (ll i = 0; i <= k; i++)
    {
        ll dis = g[i] - loc;
        loc = g[i];
        if (gas < dis)
            return false;
        t += 2 * dis;
        t -= min(dis, (gas - dis));
        // var(dis, loc, t);
    }
    if (t > tim)
    {
        return false;
    }
    return true;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> k >> s >> tim;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll c, gas;
        cin >> c >> gas;
        mp[c] = max(mp[c], gas);
    }
    for (ll i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        g.pb(x);
    }
    g.pb(s);
    sort(all(g));
    ll val = 0;
    for (auto &x : mp)
    {
        if (x.ss > val)
        {
            val = x.ss;
        }
        else
        {
            x.ss = -1;
        }
    }
    for (auto x : mp)
    {
        if (x.ss != -1)
        {
            v.pb(x);
        }
    }
    sort(all(v));
    ll lo = 0, hi = v.size() - 1;
    ll res = hi + 1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        // var(lo, mid, hi);
        if (ok(mid))
        {
            res = min(res, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << (res == v.size() ? -1 : v[res].ff) << nl;
    return 0;
}