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
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll mx = 0;
        ll l = 0, r = n - 1;
        ll res = 0;
        while (l <= r)
        {
            ll temp = 0;
            if (a[l] <= a[r])
            {
                temp = a[l];
                l++;
            }
            else
            {
                temp = a[r];
                r--;
            }
            if (temp >= mx)
                res++;
            mx = max(temp, mx);
        }
        cout << "Case #" << tc << ": " << res << nl;
    }
    return 0;
}