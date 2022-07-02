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
        if (n % 2 == 0)
        {
            ll a[n + 1];
            for (ll i = 0; i <= n; i++)
            {
                cin >> a[i];
            }
            for (ll i = 1; i <= n; i++)
            {
                cout << (a[0] ^ a[i]) << " ";
            }
            cout << nl;
            continue;
        }
        ll x = 0;
        ll a[n + 5];
        for (ll i = 0; i <= n; i++)
        {
            cin >> a[i];
            x ^= a[i];
        }
        vector<ll> v;
        for (ll i = 0; i <= n; i++)
        {
            ll num = x ^ a[i];
            if (num)
                v.pb(num);
        }
        for (auto x : v)
        {
            cout << x << " ";
        }
        for (ll i = v.size(); i < n; i++)
        {
            cout << 0 << " ";
        }
        cout << nl;
    }
    return 0;
}