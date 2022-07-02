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
ll lazy[800004];

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
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void update(ll node, ll strt, ll end, ll lo, ll hi, ll val)
{
    if (strt >= lo && end <= hi)
    {
        lazy[node] += val;
    }
    else if (strt > hi || end < lo)
    {
        return;
    }
    else
    {
        ll mid = (strt + end) / 2;
        update(2 * node, strt, mid, lo, hi, val);
        update(2 * node + 1, mid + 1, end, lo, hi, val);
    }
}

ll query(ll node, ll strt, ll end, ll index)
{
    if (strt == end)
    {
        return lazy[node];
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (index <= mid)
        {
            return lazy[node] +query(2 * node, strt, mid, index);
        }
        else
        {
            return lazy[node]+query(2 * node + 1, mid + 1, end, index);
        }
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

    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    // for (ll i = 0; i < 4 * n; i++)
    //     cout << tree[i] << " ";
    // cout << nl;
    while (q--)
    {
        ll in;
        cin >> in;
        if (in == 1)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            update(1, 0, n - 1, x - 1, y - 1, w);
            // for (ll i = 0; i < 4 * n; i++)
            //     cout << lazy[i] << " ";
            // cout << nl;
        }
        else
        {
            ll z;
            cin >> z;
            cout << a[z - 1] + query(1, 0, n - 1, z - 1)<<nl;
            //cout << val << nl;
        }
    }
    return 0;
}