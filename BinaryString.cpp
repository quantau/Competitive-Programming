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

ll f[200010], b[200010];

bool ok(ll x, ll n)
{
    ll res = n + 1;
    ll j = 1;
    for (ll i = 0; i <= n; i++)
    {
        j = max(i + 1, j);
        while (f[i] + b[j] > x && j <= n)
        {
            j++;
        }
        ll val = (j - i - 1) - (f[j - 1] - f[i]);
        res = min(res, max(f[i] + b[j], val));
    }
    return res <= x;
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.size();
        for (ll i = 1, k = n; i <= n && k > 0; i++, k--)
        {
            f[i] = (s[i - 1] - '0');
            if (i > 1)
            {
                f[i] += f[i - 1];
            }
            b[k] = (s[k - 1] - '0');
            if (k < n)
            {
                b[k] += b[k + 1];
            }
        }
        b[n + 1] = 0;
        f[0] = 0;
        ll lo = 0, hi = n, res = hi + 1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid, n))
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << res << nl;
    }
    return 0;
}