
#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;
const int MAXN = 200001;
ll a[MAXN], tree_mn[4 * MAXN], tree_mx[4 * MAXN];

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree_mn[node] = a[strt];
        tree_mx[node] = a[strt];
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        tree_mn[node] = min(tree_mn[2 * node], tree_mn[2 * node + 1]);
        tree_mx[node] = max(tree_mx[2 * node], tree_mx[2 * node + 1]);
    }
}

void update(ll node, ll strt, ll end, ll ind, ll val)
{
    if (strt == end)
    {
        tree_mn[node] = val;
        tree_mx[node] = val;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (ind <= mid)
        {
            update(2 * node, strt, mid, ind, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, ind, val);
        }
        tree_mn[node] = min(tree_mn[2 * node], tree_mn[2 * node + 1]);
        tree_mx[node] = max(tree_mx[2 * node], tree_mx[2 * node + 1]);
    }
}

ll query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (tree_mn[node] >= lo && tree_mx[node] <= hi)
    {
        // var(end - strt + 1, node, strt, end);
        return end - strt + 1;
    }
    else if (tree_mn[node] > hi || tree_mx[node] < lo)
    {
        return 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        //var(strt, mid, mid + 1, end);
        ll q1 = query(2 * node, strt, mid, lo, hi);
        ll q2 = query(2 * node + 1, mid + 1, end, lo, hi);
        return q1 + q2;
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
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    // for (ll i = 0; i < 4 * n; i++)
    // {
    //     cout << tree_mn[i] << " ";
    // }
    // cout << nl;
    // for (ll i = 0; i < 4 * n; i++)
    // {
    //     cout << tree_mx[i] << " ";
    // }
    // cout << nl;
    while (q--)
    {
        char c;
        ll x, y;
        cin >> c >> x >> y;
        if (c == '!')
        {
            update(1, 0, n - 1, --x, y);
            // for (ll i = 0; i < 4 * n; i++)
            // {
            //     cout << tree_mn[i] << " ";
            // }
            // cout << nl;
            // for (ll i = 0; i < 4 * n; i++)
            // {
            //     cout << tree_mx[i] << " ";
            // }
            // cout << nl;
        }
        else
        {
            cout << query(1, 0, n - 1, x, y) << nl;
        }
    }
    return 0;
}