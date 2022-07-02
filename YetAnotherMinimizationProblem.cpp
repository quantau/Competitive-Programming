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
        ll sum = 0, sum2 = 0, sall = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            sall += a[i];
            sum2 += a[i] * a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            sall += b[i];
            sum2 += b[i] * b[i];
        }
        ll dp[sall][n];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < sall; j++)
            {
                dp[j][i] = 0;
            }
        }
        dp[a[0]][0] = 1;
        dp[b[0]][0] = 1;
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 1; j < sall; j++)
            {
                if (j - a[i] > 0 && dp[j - a[i]][i - 1])
                {
                    dp[j][i] = 1;
                }
                if (j - b[i] > 0 && dp[j - b[i]][i - 1])
                {
                    dp[j][i] = 1;
                }
            }
        }
        ll res = 1e17;
        for (ll i = 1; i < sall; i++)
        {
            if (dp[i][n - 1])
            {
                res = min(res, i * i + (sall - i) * (sall - i));
                // var(i, res, -1);
            }
        }
        cout << res + sum2 * (n - 2) << nl;
    }
    return 0;
}