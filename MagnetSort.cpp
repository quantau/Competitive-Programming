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
        ll a[n], b[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        string s;
        cin >> s;
        ll p[n];
        bool b11 = false, b0 = false;
        for (ll i = 0; i < n; i++)
        {
            p[i] = (s[i] == 'N' ? 1 : 0);
            if (p[i] == 1)
            {
                b11 = true;
            }
            if (p[i] == 0)
            {
                b0 = 1;
            }
        }
        sort(b, b + n);
        bool c = true;
        for (ll i = 0; i < n; i++)
        {
            if (b[i] != a[i])
            {
                c = false;
                break;
            }
        }
        if (c)
        {
            cout << 0 << nl;
            continue;
        }
        if (!b11 || !b0)
        {
            cout << -1 << nl;
            continue;
        }
        if (p[0] != p[n - 1])
        {
            cout << 1 << nl;
            continue;
        }
        ll l = -1, r = n;
        bool b1 = false, b2 = false;
        for (ll i = 0; i < n; i++)
        {
            b1 = (p[i] != p[0]);
            if (a[i] != b[i])
            {
                break;
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            // b2 = (p[i] != p[n - 1]);
            // var(p[i], p[n - 1], -i);
            if (a[i] != b[i])
            {
                break;
            }
        }
        // var(b1, b2, -1);
        if (b1 || b2)
        {
            cout << 1 << nl;
            continue;
        }
        cout << 2 << nl;
    }
    return 0;
}