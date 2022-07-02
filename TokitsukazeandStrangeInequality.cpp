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
        ll p[n][n];
        for (ll i = 1; i < n - 1; i++)
        {
            p[i][n - 1] = (a[n - 1] < a[i]);
            for (ll j = n - 2; j > i; j--)
            {
                p[i][j] = p[i][j + 1] + (a[j] < a[i]);
            }
        }
        ll res = 0;
        for (ll i = 1; i < n - 1; i++)
        {
            ll val = 0;
            for (ll j = 0; j < i; j++)
            {
                val += p[j][i + 1];
            }
            for (ll j = 0; j < i; j++)
            {
                val -= p[j][i + 1];
                if (a[j] < a[i])
                {
                    res += val;
                }
            }
        }
        cout << res << nl;
    }
    return 0;
}