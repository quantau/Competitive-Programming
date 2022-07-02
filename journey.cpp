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
        ll f[n + 1] = {0};
        ll b[n + 1] = {0};
        for (ll i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'L')
            {
                if (i > 2 && s[i - 2] == 'R' && s[i - 3] == 'L')
                {
                    f[i] += f[i - 2] + 1;
                }
                else if (i >= 2 && s[i - 2] == 'R')
                {
                    f[i]++;
                }
                f[i]++;
            }
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'R')
            {
                if (i <= n - 3 && s[i + 1] == 'L' && s[i + 2] == 'R')
                {
                    b[i] += b[i + 2] + 1;
                }
                else if (i <= n - 2 && s[i + 1] == 'L')
                {
                    b[i]++;
                }
                b[i]++;
            }
        }
        for (ll i = 0; i <= n; i++)
        {
            // var(i, f[i], b[i]);
            cout << 1 + f[i] + b[i] << " ";
        }
        cout << nl;
    }
    return 0;
}