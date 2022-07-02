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

double dp[205][205][205];

int main()
{
    FASTIO

    ll n, l, k;
    cin >> n >> l >> k;
    k = min(n, k);
    double p[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        p[i] /= 100;
    }
    ll cap[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> cap[i];
        cap[i]++;
    }
    dp[0][0][k] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            for (ll l = k; l <= n; l++)
            {
                ll x = min(n, cap[i] + l);
                dp[i][j + 1][x] += dp[i - 1][j][l] * p[i];
                dp[i][j][l] += dp[i - 1][j][l] * (1 - p[i]);
            }
        }
    }
    double res = 0;
    for (ll i = l; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            res += dp[n][i][j];
        }
    }
    cout << setprecision(14) << res << nl;
    return 0;
}