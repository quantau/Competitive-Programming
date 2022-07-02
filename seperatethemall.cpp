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
        ll n, q;
        cin >> n >> q;
        ll a[n + 1] = {};
        ll ans = 1;
        for (ll i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            a[u]++;
            a[v]++;
        }
        for (ll x = 1; x <= n; x++)
        {
            ans += (a[x] * (a[x] + 1)) / 2 - 1;
            // var(x, a[x], ans);
        }
        cout << ans << nl;
        ll res = ans;
        while (q--)
        {
            ll x, y, c, d;
            cin >> x >> y >> c >> d;
            ans -= a[x];
            ans -= a[y];
            a[x]--, a[y]--;
            ans += a[c] + 1;
            ans += a[d] + 1;
            a[x]++, a[y]++;
            cout << ans << nl;
            ans = res;
        }
    }
    return 0;
}