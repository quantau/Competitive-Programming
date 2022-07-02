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
        ll c[n], v[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<ll> vec;
        for (ll i = 0; i < n; i++)
        {
            if (c[i] % 2)
            {
                vec.pb(v[i]);
            }
        }
        if (vec.empty())
        {
            cout << 0 << nl;
            continue;
        }
        reverse(all(vec));
        ll m = vec.size();
        ll dp[m];
        dp[0] = vec[0];
        for (ll i = 1; i < m; i++)
        {
            dp[i] = max(vec[i] - dp[i - 1], dp[i - 1]);
        }
        cout << dp[m - 1] << nl;
    }
    return 0;
}