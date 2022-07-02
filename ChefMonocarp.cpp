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

    ll inf = 1e9 + 7;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
       // ll inf = 2 * n + 7;
        ll a[n + 1];
        a[0] = 0;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n + 1);
        ll dp[n + 1][2 * n + 6];
        for (ll i = 0; i <= n; i++)
        {
            dp[i][0] = inf;
        }
        for (ll i = 0; i <= 2 * n + 5; i++)
        {
            dp[0][i] = 0;
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= 2 * n + 5; j++)
            {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(a[i] - j));
            }
        }
        // for (ll i = 0; i <= n; i++)
        // {
        //     for (ll j = 0; j <= 2 * n + 5; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << nl;
        // }
        cout << dp[n][2 * n + 5] << nl;
    }
    return 0;
}