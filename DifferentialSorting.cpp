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
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (a[n - 1] >= 0 || a[n - 2] >= 0)
        {
            if (a[n - 2] > a[n - 1])
            {
                cout << -1 << nl;
            }
            else
            {
                cout << n - 2 << nl;
                for (ll i = 0; i < n - 2; i++)
                {
                    cout << i + 1 << " " << n - 1 << " " << n << nl;
                }
            }
        }
        else
        {
            bool b = true;
            for (ll i = 1; i < n; i++)
            {
                if (a[i - 1] > a[i])
                {
                    b = false;
                    break;
                }
            }
            if (b)
            {
                cout << 0 << nl;
            }
            else
            {
                cout << -1 << nl;
            }
        }
    }
    return 0;
}