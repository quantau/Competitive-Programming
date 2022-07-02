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
ll tree[400004];

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

void update(ll node, ll strt, ll end, ll val)
{
    if (strt == end)
    {
        tree[node] = 0;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (val <= mid)
        {
            update(2 * node, strt, mid, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, ll strt, ll end, ll val)
{
    if (strt == end)
    {
        // var(node, strt, a[strt]);
        return strt;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (tree[2 * node] >= val)
        {
            return query(2 * node, strt, mid, val);
        }
        else
        {
            return query(2 * node + 1, mid + 1, end, val - tree[2 * node]);
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

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        a[i + 1] = 1;
    }
    build(1, 1, n);
    ll r[n];

    for (ll i = n - 1; i >= 0; i--)
    {
        // for (ll i = 0; i < 4 * n; i++)
        // {
        //     cout << tree[i] << " ";
        // }
        // cout << nl;
        r[i] = query(1, 1, n, i + 1 - arr[i]);
        update(1, 1, n, r[i]);
    }
    for (ll i = 0; i < n; i++)
    {
        cout << r[i] << " ";
    }
    cout << nl;
    return 0;
}