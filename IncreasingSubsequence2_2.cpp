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
ll a[200001];
ll tree[800004];

void build(ll node, ll strt, ll en)
{
    if (strt == en)
    {
        tree[node] = a[strt];
    }
    else
    {
        ll mid = (en + strt) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, en);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void update(ll node, ll strt, ll en, ll ind, ll val)
{
    if (strt == en)
    {
        tree[node] = val;
    }
    else
    {
        ll mid = (strt + en) / 2;
        if (ind <= mid)
            update(2 * node, strt, mid, ind, val);
        else
        {
            update(2 * node + 1, mid + 1, en, ind, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, ll strt, ll en, ll lo, ll hi)
{
    if (lo <= strt && hi >= en)
        return tree[node];
    else if (lo > en || hi < strt)
        return 0;
    ll mid = (strt + en) / 2;
    ll q1 = query(2 * node, strt, mid, lo, hi);
    ll q2 = query(2 * node + 1, mid + 1, en, lo, hi);
    return (q1 + q2);
}
using namespace std;

ll mod = 1e9 + 7;
ll a[200001];
ll tree[800004];

ll query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (strt >= lo && end <= hi)
    {
        return tree[node] % mod;
    }
    else if (strt > hi || end < lo)
    {
        return 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        ll q1 = query(2 * node, strt, mid, lo, hi) % mod;
        ll q2 = query(2 * node + 1, mid + 1, end, lo, hi) % mod;
        return (q1 + q2) % mod;
    }
}

void update(ll node, ll strt, ll end, ll scr, ll val)
{
    if (strt == end)
    {
        tree[node] += val % mod;
        tree[node] %= mod;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (scr <= mid)
        {
            update(2 * node, strt, mid, scr, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, scr, val);
        }
        tree[node] = (tree[2 * node] % mod + tree[2 * node + 1] % mod) % mod;
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

    ll n;
    cin >> n;
    ll a[n];
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    ll c = 1;
    for (auto &x : mp)
    {
        x.ss = c;
        c++;
    }
    for (ll i = 0; i < n; i++)
    {
        a[i] = mp[a[i]];
    }
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll p = ((query(1, 0, n - 1, 1, a[i] - 1)) + 1) % mod;
        res += p;
        res %= mod;
        update(1, 0, n - 1, a[i], p);
    }
    cout << res << nl;
    return 0;
}