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

ll a[100001];
ll tree[3][400004];
ll lazy[400004];

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[0][node] = 1;
        tree[1][node] = 0;
        tree[2][node] = 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        tree[0][node] = tree[0][2 * node] + tree[0][2 * node + 1];
        tree[1][node] = tree[1][2 * node] + tree[1][2 * node + 1];
        tree[2][node] = tree[2][2 * node] + tree[2][2 * node + 1];
    }
}

void shift(ll node)
{
    ll temp = tree[0][node];
    tree[0][node] = tree[2][node];
    tree[2][node] = tree[1][node];
    tree[1][node] = temp;
}

void update(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (lazy[node])
    {
        ll add = lazy[node];
        lazy[node] = 0;
        if (strt != end)
        {
            lazy[2 * node] += add;
            lazy[2 * node + 1] += add;
        }
        add %= 3;
        for (ll i = 0; i < add; i++)
        {
            shift(node);
        }
    }
    if (strt >= lo && end <= hi)
    {
        shift(node);
        if (strt != end)
        {
            lazy[2 * node]++;
            lazy[2 * node + 1]++;
        }
    }
    else if (strt > hi || end < lo)
    {
        return;
    }
    else
    {
        ll mid = (strt + end) / 2;
        update(2 * node, strt, mid, lo, hi);
        update(2 * node + 1, mid + 1, end, lo, hi);
        for (ll i = 0; i < 3; i++)
        {
            tree[i][node] = tree[i][2 * node] + tree[i][2 * node + 1];
        }
    }
}

ll query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (lazy[node])
    {
        ll add = lazy[node];
        lazy[node] = 0;
        if (strt != end)
        {
            lazy[2 * node] += add;
            lazy[2 * node + 1] += add;
        }
        add %= 3;
        for (ll i = 0; i < add; i++)
        {
            shift(node);
        }
    }
    if (strt >= lo && end <= hi)
    {
        return tree[0][node];
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

    ll n, k;
    cin >> n >> k;
    build(1, 0, n - 1);
    while (k--)
    {
        ll q, x, y;
        cin >> q >> x >> y;
        if (q == 1)
        {
            cout << query(1, 0, n - 1, x, y) << nl;
        }
        else
        {
            update(1, 0, n - 1, x, y);
        }
        // for (ll i = 1; i <= 4 * n; i++)
        // {
        //     cout << tree[0][i] << " ";
        // }
        // cout << nl;
    }
    return 0;
}