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
        ll a, b, n;
        cin >> a >> b >> n;
        n--;
        if (a == b)
        {
            cout << 0 << nl;
            continue;
        }
        ll val = 0;
        ll num = 0;
        for (ll i = 0; i <= 30; i++)
        {
            if ((a & (1 << i)) == (b & (1 << i)))
            {
                continue;
            }
            else
            {
                val += (1 << i);
                num = (1 << i);
            }
        }
        if (n < num)
        {
            cout << -1 << nl;
        }
        else if (n >= val)
        {
            cout << 1 << nl;
        }
        else
        {
            cout << 2 << nl;
        }
    }
    return 0;
}