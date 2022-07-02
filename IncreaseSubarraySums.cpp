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

ll n, x;
ll pref[5005];
ll a[5005];
ll mx[5005];

void calc(ll x, ll n)
{
    ll res = -1e17;
    for (ll i = x; i <= n; i++)
    {
        res = max(res, pref[i] - pref[i - x]);
    }
    mx[x] = res;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + a[i];
        }
        for (ll i = 0; i <= n; i++)
        {
            calc(i, n);
        }
        for (ll i = 0; i <= n; i++)
        {
            ll res = 0;
            for (ll j = 0; j <= n; j++)
            {
                res = max(res, mx[j] + min(j, i) * x);
            }
            cout << res << " ";
        }
        cout << nl;
    }
    return 0;
}