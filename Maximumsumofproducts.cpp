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

    ll n;
    cin >> n;
    ll a[n], b[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll pref[n];
    for (ll i = 0; i < n; i++)
    {
        pref[i] = a[i] * b[i];
        if (i >= 1)
        {
            pref[i] += pref[i - 1];
        }
    }
    ll res = pref[n - 1], val = pref[n - 1];
    for (ll i = 0; i < n; i++)
    {
        ll val1 = 0, val2 = 0;
        for (ll j = i - 1, k = i + 1; j >= 0 && k < n; j--, k++)
        {
            val1 += a[k] * b[j] + a[j] * b[k];
            val2 += a[k] * b[k] + a[j] * b[j];
            res = max(res, val - val2 + val1);
        }
        val1 = 0, val2 = 0;
        for (ll j = i, k = i + 1; j >= 0 && k < n; j--, k++)
        {
            val1 += a[k] * b[j] + a[j] * b[k];
            val2 += a[k] * b[k] + a[j] * b[j];
            res = max(res, val - val2 + val1);
        }
    }
    cout << res << nl;
    return 0;
}