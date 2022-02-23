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
#define FREOPEN                           \
    freopen("convention.in", "r", stdin); \
    freopen("convention.out", "w", stdout);

using namespace std;

ll n, m, c;
ll a[100001];

bool ok(ll x)
{
    ll j = 0;
    ll bus = 1;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] - a[j] > x || i - j + 1 > c)
        {
            bus++;
            j = i;
        }
    }
    return bus <= m;
}

int main()
{
    FASTIO
    FREOPEN
    cin >> n >> m >> c;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    ll lo = 0, hi = a[n - 1] - a[0];
    ll res = hi + 1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (ok(mid))
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
    return 0;
}