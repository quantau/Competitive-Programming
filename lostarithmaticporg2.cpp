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

const ll mod = 1e9 + 7;

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll b, d1, n1, c, d2, n2;
        cin >> b >> d1 >> n1 >> c >> d2 >> n2;
        ll d = d2;
        ll bl = b + d1 * (n1 - 1);
        ll cl = c + d2 * (n2 - 1);
        if (cl > bl || c < b || (c - b) % d1 || __gcd(d1, d2) != d1)
        {
            cout << 0 << nl;
            continue;
        }
        else if (cl + d2 > bl || c - d2 < b)
        {
            cout << -1 << nl;
            continue;
        }
        ll res = 0;
        for (ll i = 1; i * i <= d2; i++)
        {
            ll l = (i / (__gcd(i, d1))) * d1;
            if (l == d2)
            {
                res += (d2 / i) * (d2 / i);
                res %= mod;
            }
            if (d2 % i == 0 && i != d2 / i)
            {
                ll j = d2 / i;
                l = (j / (__gcd(j, d1))) * d1;
                if (l == d2)
                {
                    res += (d2 / j) * (d2 / j);
                    res %= mod;
                }
            }
        }
        cout << res % mod << nl;
    }
    return 0;
}