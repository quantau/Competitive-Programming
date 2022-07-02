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
const int MAXN = 300001;
vector<ll> a(MAXN, 0);
ll tree[4 * MAXN];
ll lazy[4 * MAXN];

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[node] = strt + 1;
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
    }
}

void update(ll node, ll strt, ll end, ll l, ll r, ll x)
{
    if (lazy[node])
    {
        tree[node] = lazy[node];
        if (strt != end)
        {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if (strt >= l && end <= r)
    {
        tree[node] = x;
        if (strt != end)
        {
            lazy[2 * node] = x;
            lazy[2 * node + 1] = x;
        }
    }
    else if (strt > r || end < l || l > r || strt > end)
    {
        return;
    }
    else
    {
        ll mid = (strt + end) / 2;
        update(2 * node, strt, mid, l, r, x);
        update(2 * node + 1, mid + 1, end, l, r, x);
    }
}

ll query(ll node, ll strt, ll end, ll ind)
{
    if (lazy[node])
    {
        ll x = lazy[node];
        tree[node] = x;
        if (strt != end)
        {
            lazy[2 * node] = x;
            lazy[2 * node + 1] = x;
        }
        lazy[node] = 0;
    }
    if (strt == end)
    {
        return tree[node];
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (ind <= mid)
        {
            query(2 * node, strt, mid, ind);
        }
        else
        {
            query(2 * node + 1, mid + 1, end, ind);
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

    ll n, m;
    cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        ll y;
        for (ll i = l; i <= r; i = y)
        {
            y = query(1, 1, n, i);
            if (!a[i])
            {
                if (i < x)
                {
                    update(1, 1, n, i, i, x);
                    a[i] = x;
                }
                else if (i > x)
                {
                    update(1, 1, n, i, i, r + 1);
                    a[i] = x;
                }
                else
                {
                    update(1, 1, n, i, i, r + 1);
                }
            }
        }
        update(1, 1, n, l, x - 1, x);
        update(1, 1, n, x, r, r + 1);
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << nl;
    return 0;
}

// 300000 28
// 1 150001 150001
// 2 150002 150002
// 3 150003 150003
// 4 150004 150004
// 5 150005 150005
// 6 150006 150006
// 7 150007 150007
// 8 150008 150008
// 9 150009 150009
// 10 150010 150010
// 11 150011 150011
// 12 150012 150012
// 13 150013 150013
// 14 150014 150014
// 15 150015 150015
// 16 150016 150016
// 17 150017 150017
// 18 150018 150018
// 19 150019 150019
// 20 150020 150020
// 21 150021 150021
// 22 150022 150022
// 23 150023 150023
// 24 150024 150024
// 25 150025 150025
// 26 150026 150026
// 27 150027 150027
// 28 150028 150028