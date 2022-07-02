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
int dp[205][205][205]; // dp[i][j][k]--> i index, j is max suffix,k is min suffix

const int mod = 998244353;

int main()
{
    FASTIO

    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'A')
        {
            a[i] = 1;
        }
        else if (s[i - 1] == 'B')
        {
            a[i] = -1;
        }
        else
        {
            a[i] = 0;
        }
    }

    if (a[1] == 0)
    {
        dp[1][1][0] = 1;
        dp[1][0][1] = 1;
    }
    else
    {
        dp[1][max(a[1], (ll)0)][max(-a[1], (ll)0)] = 1;
    }

    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            for (ll k = 0; k < m; k++)
            {
                if (!dp[i][j][k])
                    continue;
                // var(i, j, k);
                if (a[i + 1] == 1 || a[i + 1] == 0)
                {
                    dp[i + 1][max(j + 1, (ll)1)][max(k - 1, (ll)0)] += dp[i][j][k];
                    dp[i + 1][max(j + 1, (ll)1)][max(k - 1, (ll)0)] %= mod;
                }
                if (a[i + 1] == -1 || a[i + 1] == 0)
                {
                    dp[i + 1][max(j - 1, (ll)0)][max(k + 1, (ll)1)] += dp[i][j][k];
                    dp[i + 1][max(j - 1, (ll)0)][max(k + 1, (ll)1)] %= mod;
                }
            }
        }
    }

    ll res = 0;
    for (ll j = 0; j < m; j++)
    {
        for (ll k = 0; k < m; k++)
        {
            res += dp[n][j][k];
            res %= mod;
        }
    }
    cout << res << nl;
    return 0;
}