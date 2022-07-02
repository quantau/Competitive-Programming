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

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ordered_set o_set;
    ll n, q;
    cin >> n >> q;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        o_set.insert({a[i], i});
    }
    while (q--)
    {
        char c;
        ll x, y;
        cin >> c >> x >> y;
        if (c == '!')
        {
            o_set.erase({a[x], x});
            o_set.insert({y, x});
            a[x] = y;
        }
        else
        {
            cout << o_set.order_of_key({y + 1, 0}) - o_set.order_of_key({x, 0}) << nl;
        }
    }
    return 0;
}