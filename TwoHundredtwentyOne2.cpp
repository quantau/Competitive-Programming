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
        ll a[n], b[n];
        string s;
        cin >> s;
        map<pii, set<ll>> mp;
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
            b[i] = (s[i] == '+' ? 1 : -1);
        }
        for (ll i = 0; i < n - 1; i++)
        {
            // var(a[i], b[i + 1], i);
            mp[{a[i], b[i + 1]}].insert(i + 1);
        }
        // for (auto x : mp)
        // {
        //     cout << x.ff.ff << " " << x.ff.ss << endl;
        //     for (auto z : x.ss)
        //     {
        //         cout << z << " ";
        //     }
        //     cout << endl;
        // }

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
                continue;
            }
            else if (val % 2)
            {
                cout << 1 << nl;
            }
            else
            {
                cout << 2 << nl;
                cout << l + 1 << " ";
                l++;
            }
            ll num = val / 2;
            if (l)
            {
                num += a[l - 1];
            }
            if (l == r)
            {
                cout << l + 1 << nl;
                continue;
            }
            var(num, l, -1);
            if (val > 0)
            {
                auto it = mp[{num, 1}].lower_bound(l);
                cout << *it + 1 << nl;
            }
            else
            {
                auto it = mp[{num, -1}].lower_bound(l);
                cout << *it + 1 << nl;
            }
        }
    }
    return 0;
}