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

ll a[200001];
ll tree[800004];

void update(ll node, ll strt, ll end, ll lo, ll hi, ll val)
{
    // var(strt, end, lo, hi);
    if (strt >= lo && end <= hi)
    {
        tree[node] += val;
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

ll query(ll node, ll strt, ll end, ll val)
{
    // var(node, strt, end, val);
    if (strt == end)
    {
        return tree[node];
    }
    else
    {
        ll mid = (strt + end) / 2;
        ll q = tree[node];
        if (val <= mid)
        {
            q += query(2 * node, strt, mid, val);
        }
        else
        {
            q += query(2 * node + 1, mid + 1, end, val);
        }
        return q;
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
    while (m--)
    {
        // for (ll i = 1; i < 4 * n; i++)
        // {
        //     cout << tree[i] << " ";
        // }
        // cout << nl;
        ll q;
        // dbg(3);
        cin >> q;
        if (q == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            update(1, 0, n - 1, l, r - 1, val);
        }
        else if (q == 2)
        {
            // dbg(1);
            ll index;
            cin >> index;
            cout << query(1, 0, n - 1, index) << nl;
        }
    }
    return 0;
}