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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[2][n];
        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        ll dp[2][n]; //0--> top 1--> bottom
        dp[0][0] = a[0][0];
        dp[1][0] = a[1][0];
        for (ll i = 1; i < n; i++)
        {
            dp[0][i]=max(dp[0][i-1]^a[0][])
        }
    }
    return 0;
}