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

int main()
{
    FASTIO

    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        ll sum = (n * (n + 1)) / 2;
        if ((x * sum) % (x + y) == 0)
        {
            cout << "Case #" << tc << ": POSSIBLE\n";
            ll val = (x * sum) / (x + y);
            ll curr = n;
            vector<ll> res;
            while (val && val >= curr)
            {
                res.pb(curr);
                val -= curr;
                curr--;
            }
            if (val)
            {
                res.pb(val);
            }
            cout << res.size() << nl;
            for (auto x : res)
            {
                cout << x << " ";
            }
            cout << nl;
        }
        else
        {
            cout << "Case #" << tc << ": IMPOSSIBLE\n";
        }
    }
    return 0;
}