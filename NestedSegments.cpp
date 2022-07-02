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

const int MAXN = 200001;
ll a[MAXN];
vector<ll> tree[4 * MAXN];

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[node].pb(a[strt]);
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        ll j = 0;
        ll lim = tree[2 * node].size();
        for (auto x : tree[2 * node + 1])
        {
            while (j < lim && tree[2 * node][j] <= x)
            {
                tree[node].pb(tree[2 * node][j]);
                j++;
            }
            tree[node].pb(x);
        }
        while (j < lim)
        {
            tree[node].pb(tree[2 * node][j]);
            j++;
        }
    }
}

ll query(ll node, ll strt, ll end, ll lo, ll hi, ll val)
{
    if (strt >= lo && end <= hi)
    {
        return tree[node].size() - (lower_bound(all(tree[node]), val + 1) - tree[node].begin());
    }
    else if (strt > hi || end < lo)
    {
        return 0;
    }
    ll mid = (strt + end) / 2;
    ll q1 = query(2 * node, strt, mid, lo, hi, val);
    ll q2 = query(2 * node + 1, mid + 1, end, lo, hi, val);
    return q1 + q2;
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
    vector<pii> v(2 * n + 1, {-1, -1});
    for (ll i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
        if (v[a[i]].ff == -1)
        {
            v[a[i]].ff = i;
        }
        else
        {
            v[a[i]].ss = i;
        }
    }
    vector<ll> occ(2 * n + 1, -1);
    for (ll i = 0; i < 2 * n; i++)
    {
        ll val = a[i];
        a[i] = occ[val];
        occ[val] = i;
    }
    build(1, 0, 2 * n - 1);
    // for (ll i = 1; i < 8 * n; i++)
    // {
    //     for (auto x : tree[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << nl;
    // }
    for (ll i = 1; i <= n; i++)
    {
        cout << query(1, 0, 2 * n - 1, v[i].ff, v[i].ss, v[i].ff) << " ";
    }
    return 0;
}