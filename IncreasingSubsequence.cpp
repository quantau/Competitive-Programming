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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

ll a[200005];
ll tree[800020];

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
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

ll query(ll node, ll strt, ll en, ll lo, ll hi)
{
    if (lo > hi)
        return 0;
    if (lo <= strt && hi >= en)
        return tree[node];
    else if (lo > en || hi < strt)
        return 0;
    ll mid = (strt + en) / 2;
    ll q1 = query(2 * node, strt, mid, lo, hi);
    ll q2 = query(2 * node + 1, mid + 1, en, lo, hi);
    return max(q1, q2);
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0; i <= 4 * n; i++)
    {
        tree[i] = 0;
    }
    ll l[n], r[n];
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        a[i] = arr[i];
    }
    sort(arr, arr + n);
    map<ll, ll> mp;
    ll val = 0;
    for (ll i = 0; i < n; i++)
    {
        if (mp[arr[i]])
            continue;
        mp[arr[i]] = val;
        val++;
    }
    for (ll i = 0; i < n; i++)
    {
        ll lis = query(1, 0, n - 1, 0, mp[a[i]] - 1) + 1;
        l[i] = lis;
        update(1, 0, n - 1, mp[a[i]], lis);
    }
    for (ll i = 0; i <= 4 * n; i++)
    {
        tree[i] = 0;
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        ll lds = query(1, 0, n - 1, mp[a[i]] + 1, n - 1) + 1;
        r[i] = lds;
        update(1, 0, n - 1, mp[a[i]], lds);
    }
    for (ll i = 1; i < n; i++)
    {
        l[i] = max(l[i], l[i - 1]);
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i], r[i + 1]);
    }
    ll res = max(l[n - 1], r[0]);
    for (ll i = 0; i < n - 1; i++)
    {
        res = max(res, l[i] + r[i + 1]);
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << l[i] << " ";
    // }
    // cout << nl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << r[i] << " ";
    // }
    // cout << nl;
    cout << res << nl;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}