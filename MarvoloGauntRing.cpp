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

ll zero = 0;

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, p[3];
    cin >> n >> p[0] >> p[1] >> p[2];
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll dp[n][3];
    dp[0][0] = p[0] * a[0];
    dp[0][1] = dp[0][0] + p[1] * a[0];
    dp[0][2] = dp[0][1] + p[2] * a[0];
    for (ll i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], p[0] * a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i][0] + p[1] * a[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i][1] + p[2] * a[i]);
    }
    cout << dp[n - 1][2] << nl;
    return 0;
}