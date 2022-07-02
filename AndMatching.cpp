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
        ll n, k;
        cin >> n >> k;
        if (n == 4 && k == 3)
        {
            cout << -1 << nl;
            continue;
        }
        if (k == n - 1)
        {
            cout << n - 1 << " " << n - 2 << nl;
            cout << 1 << " " << n - 3 << nl;
            cout << 0 << " " << 2 << nl;
            for (ll i = 3; i < n / 2; i++)
            {
                cout << i << " " << n - 1 - i << nl;
            }
        }
        else if (k == 0)
        {
            for (ll i = 0; i < n / 2; i++)
            {
                cout << i << " " << n - 1 - i << nl;
            }
        }
        else
        {
            cout << k << " " << n - 1 << nl;
            cout << n - k - 1 << " " << 0 << nl;
            for (ll i = 1; i < n / 2; i++)
            {
                if (i == k || i == n - k - 1)
                    continue;
                cout << i << " " << n - i - 1 << nl;
            }
        }
    }
    return 0;
}