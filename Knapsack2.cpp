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

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, W;
    cin >> n >> W;
    ll w[n + 1], val[n + 1], mx = 0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> w[i] >> val[i];
        mx += val[i];
    }
    ll dp[n + 1][mx + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= mx; j++)
        {
            dp[i][j] = W + 1;
        }
        dp[i][0] = 0;
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = mx; j >= 0; j--)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //      cout << nl;
    // }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = mx; j >= 0; j--)
        {
            if (j - val[i] >= 0)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - val[i]] + w[i]);
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            }
        }
    }

    // for (ll i = 0; i <= n; i++)
    // {
    //     for (ll j = 0; j <= mx; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << nl;
    // }

    for (ll i = mx; i >= 0; i--)
    {
        if (dp[n][i] <= W)
        {
            cout << i << nl;
            return 0;
        }
    }
    return 0;
}

// 3 8
// 3 3
// 4 5
// 5 6
