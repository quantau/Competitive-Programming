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
        ll n, x;
        cin >> n >> x;
        ll a[n];
        ll res = 0;
        ll mn = 1e6, mx = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
            if (i)
                res += abs(a[i] - a[i - 1]);
        }
        ll gp = 0;
        if (x < mn)
        {
            gp = min(a[0] - 1, a[n - 1] - 1);
            for (ll i = 1; i < n; i++)
            {
                gp = min(gp, a[i] + a[i - 1] - 2 - abs(a[i] - a[i - 1]));
            }
        }
        else if (x >= mn && x < mx)
        {
            gp = min({a[0] - 1, a[n - 1] - 1, 2 * (mn - 1)});
        }
        else
        {
            gp = min({a[0] - 1, a[n - 1] - 1, 2 * (mn - 1)}) + min({x - a[0], x - a[n - 1], 2 * (x - mx)});
        }
        cout << res + gp << nl;
    }
    return 0;
}
