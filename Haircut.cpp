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

    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> freq(n + 1, 0);
    ordered_set s;
    ll inv[n];
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        s.insert({a[i], i});
        inv[i] = i + 1 - s.order_of_key({a[i] + 1, 0});
        freq[a[i]] += inv[i];
        res += inv[i];
    }
    ll r[n];
    for (ll i = n - 1; i >= 0; i--)
    {
        res -= freq[i];
        r[i] = res;
    }
    for (ll i = 0; i < n; i++)
    {
        cout << r[i] << nl;
    }
    return 0;
}