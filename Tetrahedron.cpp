#include <bits/stdc++.h>
#define sz(x) x.size()
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<int, int>
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

    int mod = 1e9 + 7;
    int n;
    cin >> n;
    int dp[4];
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll dp2[4];
        ll val = 0;
        for (ll j = 0; j < 4; j++)
        {
            (val += dp[j]) %= mod;
        }
        for (ll j = 0; j < 4; j++)
        {
            dp2[j] = (mod + val - dp[j]) % mod;
        }
        for (ll j = 0; j < 4; j++)
        {
            dp[j] = dp2[j];
        }
    }
    cout << (mod + dp[0]) % mod << nl;
    return 0;
}