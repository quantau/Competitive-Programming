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

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ordered_set s;
    s.insert(a[n - 1]);
    for (ll i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            s.insert(a[i]);
        }
        else
        {
            break;
        }
    }
    ll m = n - s.size();
    vector<ll> v;
    for (ll i = 0; i < m; i++)
    {
        ll val = (n - 1) - (s.size() - s.order_of_key(a[i]));
        s.insert(a[i]);
        v.pb(val);
    }
    cout << m << endl;
    if (m > 0)
    {
        ll num = v.back();
        v.pop_back();
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << num << nl;
    }
    return 0;
}