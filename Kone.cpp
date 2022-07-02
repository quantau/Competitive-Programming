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

void update(ll node, ll strt, ll en, ll ind)
{
    if (strt == en)
    {
        tree[node] = !tree[node];
    }
    else
    {
        ll mid = (strt + en) / 2;
        if (ind <= mid)
            update(2 * node, strt, mid, ind);
        else
        {
            update(2 * node + 1, mid + 1, en, ind);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

ll query(ll node, ll strt, ll en, ll val)
{
    if (strt == en)
    {
        return strt;
    }
    else
    {
        ll mid = (strt + en) / 2;
        if (tree[2 * node] >= val)
        {
            return query(2 * node, strt, mid, val);
        }
        else
        {
            return query(2 * node + 1, mid + 1, en, val - tree[2 * node]);
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
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (m--)
    {
        ll q, x;
        cin >> q >> x;
        if (q == 1)
        {
            update(1, 0, n - 1, x);
        }
        else
        {
            cout << query(1, 0, n - 1, x + 1) << nl;
        }
    }
    return 0;
}