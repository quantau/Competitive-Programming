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

pii p;
ll n, s;
ll inf = 1e17;
ll a[200001];
vector<ll> tree(800004, inf);

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
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
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
        return inf;
    ll mid = (strt + en) / 2;
    ll q1 = query(2 * node, strt, mid, lo, hi);
    ll q2 = query(2 * node + 1, mid + 1, en, lo, hi);
    return min(q1, q2);
}

bool ok(ll k)
{
    for (ll i = k; i <= n; i++)
    {
        ll val = query(1, 0, n, i - k, i);
        if (val + s >= a[i - k])
        {
            p = {i - k + 1, i};
            return true;
        }
    }
    return false;
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
        cin >> n >> s;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        a[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
        }
        build(1, 0, n);
        ll lo = 1, hi = n;
        ll res = 0;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (ok(mid))
            {
                res = max(res, mid);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (res)
        {
            cout << p.ff << " " << p.ss << nl;
        }
        else
        {
            cout << -1 << nl;
        }
    }
    return 0;
}