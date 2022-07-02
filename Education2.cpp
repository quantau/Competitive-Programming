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
        ll n, c;
        cin >> n >> c;
        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        ll res = 1e16;
        ll bal = 0;
        ll past = 0;
        for (ll i = 0; i < n; i++)
        {
            ll curr = (max((ll)0, c - bal) + a[i] - 1) / a[i];
            res = min(res, curr + past);
            if (i < n - 1)
            {
                ll day = (max((ll)0, (b[i] - bal)) + a[i] - 1) / a[i];
                past += day + 1;
                bal = bal - b[i] + day * a[i];
            }
            // var(res, curr, bal);
        }
        cout << res << nl;
    }
    return 0;
}