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

ll inf = 1e9 + 7, n;

ll solve(string s, string t)
{
    ll c[2] = {0, 0};
    for (ll i = 0; i < n; i++)
    {
        c[0] += s[i] - '0';
        c[1] += t[i] - '0';
    }
    if (c[0] != c[1])
        return inf;
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '1' && t[i] == '0')
            res++;
    }
    return 2 * res;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s, t;
        cin >> s >> t;
        ll val = solve(s, t);
        ll j = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1' && t[i] == '1')
            {
                j = i;
            }
            else if (s[i] == '1' && j == -1)
            {
                j = i;
            }
        }
        if (j != -1)
        {
            for (ll i = 0; i < n; i++)
            {
                if (i == j)
                    continue;
                s[i] = (s[i] == '0' ? '1' : '0');
            }
            val = min(val, solve(s, t) + 1);
        }
        cout << (val >= inf ? -1 : val) << nl;
    }
    return 0;
}