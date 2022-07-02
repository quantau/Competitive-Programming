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

ll a[200001];
ll tree[800004];

ll get_gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return get_gcd(b, a % b);
    }
}

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[node] = a[strt];
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = get_gcd(tree[2 * node], tree[2 * node + 1]);
    }
}

ll query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (strt >= lo && end <= hi)
    {
        return tree[node];
    }
    else if (strt > hi || end < lo)
    {
        return 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        ll q1 = query(2 * node, strt, mid, lo, hi);
        ll q2 = query(2 * node + 1, mid + 1, end, lo, hi);
        return get_gcd(q1, q2);
    }
}

bool ok(ll mid, ll gcd, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        ll val;
        if (i + mid < n)
        {
            val = query(1, 0, n - 1, i, i + mid);
        }
        else
        {
            val = get_gcd(query(1, 0, n - 1, i, n - 1), query(1, 0, n - 1, 0, mid - (n - i)));
        }
        //var(val, mid, i);
        if (val != gcd)
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll gcd = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            gcd = get_gcd(gcd, a[i]);
        }
        build(1, 0, n - 1);
        ll lo = 0, hi = n;
        ll res = hi + 1;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (ok(mid, gcd, n))
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << res << nl;
    }
    return 0;
}

