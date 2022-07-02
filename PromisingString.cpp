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
        string s;
        cin >> s;
        ll c[n];
        c[0] = (s[0] == '-' ? 1 : -1);
        for (ll i = 1; i < n; i++)
        {
            c[i] = (s[i] == '-' ? 1 : -1);
            c[i] += c[i - 1];
        }

        // for (ll i = 0; i < n; i++)
        // {
        //     cout << c[i] << " ";
        // }
        // cout << nl;
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (i)
                {
                    ll val = c[j] - c[i - 1];
                    res += (val >= 0 && val % 3 == 0);
                }
                else
                {
                    res += (c[j] >= 0 && c[j] % 3 == 0);
                }
            }
        }
        cout << res << nl;
    }
    return 0;
}