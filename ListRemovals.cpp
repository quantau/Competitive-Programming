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

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    ordered_set o_set;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        o_set.insert(i);
        cin >> v[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll ind;
        cin >> ind;
        ind--;
        ll in = *(o_set.find_by_order(ind));
        cout << v[in] << " ";
        o_set.erase(in);
        // for (auto x : o_set)
        //     cout << x << " ";
        // cout << nl;
    }
    return 0;
}