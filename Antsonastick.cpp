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
    for (ll tc = 1; tc <= t; tc++)
    {
        ll n, l;
        cin >> n >> l;
        vector<pair<pii, ll>> vec(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vec[i].ff.ff >> vec[i].ff.ss;
            vec[i].ss = i + 1;
        }
        vector<pii> v;
        sort(all(vec));
        ll j = 0;
        for (ll i = 0; i < n; i++)
        {
            if (vec[i].ff.ss == 0)
            {
                v.pb({vec[i].ff.ff, vec[j].ss});
                j++;
            }
        }
        j = n - 1;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (vec[i].ff.ss == 1)
            {
                v.pb({l - vec[i].ff.ff, vec[j].ss});
                j--;
            }
        }
        sort(all(v));
        cout << "Case #" << tc << ": ";
        for (auto x : v)
        {
            cout << x.ss << " ";
        }
        cout << nl;
    }
    return 0;
}