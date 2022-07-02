
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

ll dp[101][101][2];
ll mod = 1e8;

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for (ll i = 0; i <= n1; i++)
    {
        for (ll j = 0; j <= n2; j++)
        {
            for (ll l = 1; l <= k2; l++)
            {
                if (j + l > n2)
                    break;
                (dp[i][j + l][0] += dp[i][j][1] % mod) %= mod;
            }
            for (ll l = 1; l <= k1; l++)
            {
                if (i + l > n1)
                    break;
                (dp[i + l][j][1] += dp[i][j][0] % mod) %= mod;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << nl;
    return 0;
}