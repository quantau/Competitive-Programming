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
        vector<ll> type[n + 1];
        vector<ll> diff(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            diff[b[i]]++;
        }
        for (ll i = 0; i < n; i++)
        {
            type[a[i]].pb(diff[b[i]]);
        }
        ll res = (n * (n - 1) * (n - 2)) / 6;
        for (ll i = 1; i <= n; i++)
        {
            ll c = 0;
            ll m = type[i].size();
            for (auto x : type[i])
            {
                c += (x - 1) * (m - 1);
            }
            res -= c;
        }
        cout << res << nl;
    }
    return 0;
}