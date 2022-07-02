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

ll a[200001], b[200001];
ll n;

bool ok(ll m)
{
    ll sz = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] >= m - sz - 1 && b[i] >= sz)
            sz++;
    }
    return sz >= m;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        ll lo = 1, hi = n, res = 1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid))
            {
                res = max(res, mid);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << res << nl;
    }
    return 0;
}