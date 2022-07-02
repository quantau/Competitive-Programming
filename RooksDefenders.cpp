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

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    FASTIO

    ll n, q;
    cin >> n >> q;
    map<ll, ll> mp[2]; // 0--> x-axis 1-->y-axis
    ordered_set s[2];
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x, y;
            cin >> x >> y;
            mp[0][x]++, mp[1][y]++;
            if (mp[0][x] == 1)
            {
                s[0].insert(x);
            }
            if (mp[1][y] == 1)
            {
                s[1].insert(y);
            }
        }
        else if (type == 2)
        {
            ll x, y;
            cin >> x >> y;
            mp[0][x]--, mp[1][y]--;
            if (!mp[0][x])
            {
                s[0].erase(x);
            }
            if (!mp[1][y])
            {
                s[1].erase(y);
            }
        }
        else
        {
            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll xc = s[0].order_of_key(x2 + 1) - s[0].order_of_key(x1);
            ll yc = s[1].order_of_key(y2 + 1) - s[1].order_of_key(y1);
            if (xc == (x2 - x1 + 1) || yc == (y2 - y1 + 1))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}