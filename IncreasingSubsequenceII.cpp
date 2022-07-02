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
ll mod = 1e9 + 7;

ll query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (strt >= lo && end <= hi)
    {
        return tree[node] % mod;
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
        return (q1 + q2) % mod;
    }
}
void update(ll node, ll strt, ll end, ll in, ll val)
{
    if (strt == end)
    {
        (tree[node] += val) %= mod;
        a[strt] += val;
    }
    else
    {
        ll mid = (strt + end) / 2;
        if (in <= mid)
        {
            update(2 * node, strt, mid, in, val);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, in, val);
        }
        (tree[node] = tree[2 * node] + tree[2 * node + 1]) %= mod;
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
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] = 1;
    }
    ll count = 0;
    for (auto &x : mp)
    {
        x.ss = count;
        count++;
    }
    // for (auto x : mp)
    // {
    //     cout << x.ff << " " << x.ss << nl;
    // }
    for (ll i = 0; i < n; i++)
    {
        //var(arr[i], mp[arr[i]], -1);
        arr[i] = mp[arr[i]];
        // var(arr[i], mp[arr[i]], -1);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        // for (ll i = 0; i < 6; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << nl;
        ll val = 1;
        if (arr[i] == 0)
        {
            ans = (ans + val) % mod;
            update(1, 0, n - 1, arr[i], val);
            //var(i, val, arr[i]);
            continue;
        }
        val += query(1, 0, n - 1, 0, arr[i] - 1);
        ans = (ans + val) % mod;
        update(1, 0, n - 1, arr[i], val);
        //var(i, val, arr[i]);
    }
    cout << ans << nl;
    return 0;
}