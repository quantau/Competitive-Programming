#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
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

double dp[305][305][305];

int main()
{
    FASTIO

    ll n;
    cin >> n;
    ll a[n];
    ll c[4] = {0};
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        c[a[i]]++;
    }
    for (ll k = c[3]; k >= 0; k--)
    {
        for (ll j = c[3] + c[2]; j >= 0; j--)
        {
            for (ll i = n; i >= 0; i--)
            {
                if (i + j + k == 0)
                    continue;
                if (i + j + k > n)
                    continue;
                double p_waste = (double)(n - (i + j + k)) / n;
                dbg(p_waste);
                dp[i][j][k] += p_waste / ((1 - p_waste) * (1 - p_waste));
                if (i)
                {
                    double p_t = i / (i + j + k + 0.0);
                    dp[i - 1][j][k] += (dp[i][j][k] + 1) * p_t;
                }
                if (j)
                {
                    double p_t = j / (i + j + k + 0.0);
                    dp[i + 1][j - 1][k] += (dp[i][j][k] + 1) * p_t;
                }
                if (k)
                {
                    double p_t = k / (i + j + k + 0.0);
                    dp[i][j + 1][k - 1] += (dp[i][j][k] + 1) * p_t;
                }
                var(dp[i][j][k], i, j, k);
            }
        }
    }
    cout << setprecision(14) << dp[0][0][0] << nl;
    return 0;
}