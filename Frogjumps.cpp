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
        string s;
        cin >> s;
        ll n = s.size();
        ll a[n + 2];
        a[0] = 1;
        a[n + 1] = 1;
        for (ll i = 1; i <= n; i++)
        {
            a[i] = (s[i - 1] == 'L' ? 0 : 1);
        }

        ll gap = 0, fl = -1, sl = -1;

        for (ll i = 0; i < n + 2; i++)
        {
            if (!a[i])
                continue;
            if (fl == -1)
            {
                fl = i;
            }
            else if (sl == -1)
            {
                sl = i;
            }
            else
            {
                gap = max(gap, sl - fl);
                fl = sl;
                sl = i;
            }
        }

        gap = max(gap, sl - fl);
        
        cout << gap << nl;
    }
    return 0;
}