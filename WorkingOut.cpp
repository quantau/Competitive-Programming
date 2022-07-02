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

using namespace std;

ll dp[4][1002][1002];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;
    ll a[n + 1][m + 1];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            dp[0][i][j] = max(dp[0][i - 1][j], dp[0][i][j - 1]) + a[i][j];
        }
    }
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = 1; j <= m; j++)
        {
            dp[1][i][j] = max(dp[1][i + 1][j], dp[1][i][j - 1]) + a[i][j];
        }
    }
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = m; j >= 1; j--)
        {
            dp[2][i][j] = max(dp[2][i + 1][j], dp[2][i][j + 1]) + a[i][j];
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = m; j >= 1; j--)
        {
            dp[3][i][j] = max(dp[3][i - 1][j], dp[3][i][j + 1]) + a[i][j];
        }
    }
    ll res = 0;
    // cout << nl;
    // for (ll q = 0; q < 4; q++)
    // {
    //     for (ll i = 1; i <= n; i++)
    //     {
    //         for (ll j = 1; j <= m; j++)
    //         {
    //             cout << dp[q][i][j] << " ";
    //         }
    //         cout << nl;
    //     }
    //     cout << nl;
    // }
    // cout << nl;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            ll val = 0;
            if (i >= 2 && i <= n - 1 && j >= 2 && j <= m - 1)
            {
                val = max(val, dp[1][i][j - 1] + dp[0][i - 1][j] + dp[3][i][j + 1] + dp[2][i + 1][j]);
            }
            if (i >= 2 && i <= n - 1 && j >= 2 && j <= m - 1)
            {
                val = max(val, dp[0][i][j - 1] + dp[1][i + 1][j] - 2 * a[i][j] + dp[2][i][j + 1] + dp[3][i - 1][j]);
            }
            res = max(res, val);
        }
    }
    cout << res << nl;
    return 0;
}

// if (i >= 2 && i <= n - 1 && j >= 2 && j <= n - 1)
// {
//     val = dp[0][i][j] + dp[1][i][j] - 4 * a[i][j] + dp[2][i][j] + dp[3][i][j];
// }