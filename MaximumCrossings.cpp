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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        vector<ll> freq(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        ll res = 0;
        for (ll i = 1; i <= n; i++)
        {
            res += (freq[i] * (freq[i] - 1)) / 2;
        }
        // dbg(res);
        ordered_set s;
        for (ll i = 0; i < n; i++)
        {
            res += s.size() - s.order_of_key(a[i] + 1);
            s.insert(a[i]);
            // var(i, res, 0);
        }
        cout << res << nl;
    }
    return 0;
}