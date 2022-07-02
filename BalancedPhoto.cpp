
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ft[n], bk[n];
    ordered_set s;
    for (ll i = 0; i < n; i++)
    {
        s.insert({a[i], i});
        ft[i] = i + 1 - s.order_of_key({a[i] + 1, 0});
    }
    s.clear();
    for (ll i = n - 1; i >= 0; i--)
    {
        s.insert({a[i], i});
        bk[i] = n - i - s.order_of_key({a[i] + 1, 0});
    }
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll mx = max(bk[i], ft[i]);
        ll mn = min(bk[i], ft[i]);
        if (mx > 2 * mn)
        {
            res++;
            // var(a[i], mx, mn);
        }
    }
    cout << res << nl;
    return 0;
}