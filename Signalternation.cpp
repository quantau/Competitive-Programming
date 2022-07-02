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

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2)
        {
            a[i] *= -1;
        }
    }
    build(1, 0, n - 1);
    cin >> m;
    while (m--)
    {
        ll q;
        cin >> q;
        if (q == 0)
        {
            ll i, j;
            cin >> i >> j;
            i--;
            update(1, 0, n - 1, i, j * (i % 2 ? -1 : 1));
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(1, 0, n - 1, l, r) * (l % 2 ? -1 : 1) << nl;
        }
    }
    return 0;
}