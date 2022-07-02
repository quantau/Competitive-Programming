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
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll diff[n];
        for (ll i = 0; i < n; i++)
        {
            diff[i] = 1e5 + i - a[i];
        }
        vector<ll> res[20];
        ll ans = 0;
        for (ll i = 0; i < 20; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (diff[j] & (1 << i))
                {
                    res[i].pb(j + 1);
                }
            }
            ans += !(res[i].empty());
        }
        cout << ans << nl;
        for (ll i = 0; i < 20; i++)
        {
            if (!res[i].empty())
            {
                cout << res[i].size() << " " << (1 << i) << nl;
                for (auto x : res[i])
                {
                    cout << x << " ";
                }
                cout << nl;
            }
        }
    }
    return 0;
}