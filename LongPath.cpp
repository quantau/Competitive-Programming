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

const int MOD = 1e9 + 7;

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
    ll p[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        //p[i]--;
    }
    vector<ll> dp(n + 1, 1);
    dp[0] = 0;
    //dp[1] = 2;
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = (MOD + (2 * dp[i - 1] + 2 - dp[p[i] - 1]) % MOD) % MOD;
    }
    cout << dp[n] % MOD << nl;
    return 0;
}