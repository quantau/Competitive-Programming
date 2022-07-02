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
        ll n, q;
        cin >> n >> q;
        ll a[n];
        string s;
        cin >> s;
        for (ll i = 0; i < n; i++)
        {
            if (i)
            {
                a[i] = a[i - 1] + pow(-1, i) * (s[i] == '+' ? 1 : -1);
            }
            else    
            {
                a[i] = (s[i] == '+' ? 1 : -1);
            }
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            ll val;
            if (l)
            {
                val = a[r] - a[l - 1];
            }
            else
            {
                val = a[r];
            }
            if (val == 0)
            {
                cout << 0 << nl;
            }
            else if (val % 2)
            {
                cout << 1 << nl;
            }
            else
            {
                cout << 2 << nl;
            }
        }
    }
    return 0;
}