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
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n % 2)
        {
            ll res[n];
            vector<pii> v;
            for (ll i = 0; i < n; i++)
            {
                v.pb({a[i], i});
            }
            sort(all(v));
            if (v[0].ff + v[1].ff != 0)
            {
                res[v[0].ss] = -v[2].ff;
                res[v[1].ss] = -v[2].ff;
                res[v[2].ss] = v[0].ff + v[1].ff;
                for (ll i = 3; i < n; i += 2)
                {
                    res[v[i].ss] = -v[i + 1].ff;
                    res[v[i + 1].ss] = v[i].ff;
                }
            }
            else
            {

                for (ll i = 0; i < n - 3; i += 2)
                {
                    res[v[i].ss] = -v[i + 1].ff;
                    res[v[i + 1].ss] = v[i].ff;
                }
                res[v[n - 1].ss] = -v[n - 3].ff;
                res[v[n - 2].ss] = -v[n - 3].ff;
                res[v[n - 3].ss] = v[n - 1].ff + v[n - 2].ff;
            }
            for (ll i = 0; i < n; i++)
            {
                cout << res[i] << " ";
            }
        }
        else
        {
            for (ll i = 1; i < n; i += 2)
            {
                cout << -a[i] << " " << a[i - 1] << " ";
            }
        }
        cout << nl;
    }
    return 0;
}

// 8
// 3
// 1 1 1
// 3
// -1 1 1
// 3
// 1 -1 1
// 3
// 1 1 -1
// 3
// -1 -1 1
// 3
// -1 1 -1
// 3
// 1 -1 -1
// 3
// -1 -1 -1
