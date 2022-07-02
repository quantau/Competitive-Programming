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

ll solve(ll a[], ll n)
{
    set<ll> s;
    ll x = 0;
    for (ll i = 0; i < n; i++)
    {
        x ^= a[i];
        s.insert(x);
    }
    return s.size();
}

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
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            ll b[n];
            for (ll j = 0; j < n; j++)
            {
                b[(j + i) % n] = a[j];
            }
            res = max(res, solve(b, n));
            // dbg(solve(b, n));
        }
        cout << res << nl;
    }
    return 0;
}