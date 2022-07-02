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
        ll loc[n + 1];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            loc[a[i]] = i;
        }
        ll pref[n];
        pref[0] = a[0];
        for (ll i = 1; i < n; i++)
        {
            pref[i] = max(pref[i - 1], a[i]);
        }
        ll suff[n + 1];
        suff[n - 1] = a[n - 1];
        for (ll i = n - 2; i >= 0; i--)
        {
            suff[i] = min(suff[i + 1], a[i]);
        }
        suff[n] = n + 1;
        ll res = 0;
        ll r = n - 1;
        while (r >= 0)
        {
            ll mx = pref[r];
            ll mn = suff[r + 1];
            // var(mn, -1, mx);
            res++;
            if (mn < mx)
            {
                res--;
            }
            r = loc[mx] - 1;
        }
        cout << res << nl;
    }
    return 0;
}