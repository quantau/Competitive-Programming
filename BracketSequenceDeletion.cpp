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
        ll c = 0;
        ll prev = -1;
        for (ll i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                c++;
                prev = i;
                i++;
            }
            else if (s[i - 1] == '(')
            {
                c++;
                prev = i;
                i++;
            }
            else
            {
                bool b = false;
                for (ll j = i + 1; j < n; j++)
                {
                    if (s[j] == ')')
                    {
                        b = true;
                        c++;
                        i = j + 1;
                        prev = j;
                        break;
                    }
                }
                if (!b)
                {
                    break;
                }
            }
            // var(c, prev, i);
        }
        cout << c << " " << n - prev - 1 << nl;
    }
    return 0;
}