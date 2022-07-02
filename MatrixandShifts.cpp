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
        char c;
        ll a[n][n];
        ll net = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> c;
                a[i][j] = c - '0';
                net += a[i][j];
            }
        }
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            ll val = 0;
            for (ll j = 0; j < n; j++)
            {
                ll x = (j) % n;
                ll y = (i + j) % n;
                val += a[x][y];
            }
            res = max(res, val);
        }
        cout << net + n - 2 * res << nl;
    }
    return 0;
}