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

    ll n;
    cin >> n;
    ll h[2][n];
    for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> h[i][j];
        }
    }
    ll dp[3][n]; //0--> empty  1--> top filled  2-->bottom filled
    dp[0][0] = 0;
    dp[1][0] = h[0][0];
    dp[2][0] = h[1][0];
    for (ll i = 1; i < n; i++)
    {
        dp[0][i] = max({dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]});
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + h[0][i];
        dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + h[1][i];
    }
    cout << max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << nl;
    return 0;
}