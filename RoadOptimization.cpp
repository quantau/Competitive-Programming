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

    ll n, l, k;
    cin >> n >> l >> k;
    ll b[n], a[n + 1];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = l;
    for (ll i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    ll dp[n + 1][k + 1];
    ll inf = 1e11 + 7;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + b[i - 1] * (a[i] - a[i - 1]);
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            for (ll pos = 0; pos < i; pos++)
            {
                if (j - (i - pos - 1) >= 0)
                {
                    dp[i][j] = min(dp[i][j], dp[pos][j - (i - pos - 1)] + b[pos] * (a[i] - a[pos]));
                }
            }
        }
    }
    ll res = inf;
    for (ll i = 0; i <= k; i++)
    {
        res = min(res, dp[n][i]);
    }
    cout << res << nl;
    return 0;
}