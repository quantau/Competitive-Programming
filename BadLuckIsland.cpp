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

double dp[101][101][101];

// double f(double i, double j, double k)
// {
//     return i * j / (i * j + j * k + k * i);
// }

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int r, s, p;
    cin >> r >> s >> p;
    dp[r][s][p] = 1;
    for (ll i = r; i >= 0; i--)
    {
        for (ll j = s; j >= 0; j--)
        {
            for (ll k = p; k >= 0; k--)
            {
                int total = i * j + i * k + k * j;
                if (i && (j + k))
                {
                    dp[i - 1][j][k] += (dp[i][j][k] * i * k) / total;
                }
                if (j && (i + k))
                {
                    dp[i][j - 1][k] += (dp[i][j][k] * i * j) / total;
                }
                if (k && (i + j))
                {
                    dp[i][j][k - 1] += (dp[i][j][k] * j * k) / total;
                }
            }
        }
    }

    // for (ll i = r; i >= 0; i--)
    // {
    //     for (ll j = s; j >= 0; j--)
    //     {
    //         for (ll k = p; k >= 0; k--)
    //         {
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << nl;
    //     }
    //     cout << nl;
    // }

    double res[3] = {0, 0, 0};
    for (ll i = 1; i <= r; i++)
    {
        res[0] += dp[i][0][0];
    }
    for (ll i = 1; i <= s; i++)
    {
        res[1] += dp[0][i][0];
    }
    for (ll i = 1; i <= p; i++)
    {
        res[2] += dp[0][0][i];
    }
    cout << setprecision(10) << res[0] << " " << res[1] << " " << res[2] << nl;
    return 0;
}