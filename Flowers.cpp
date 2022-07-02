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

const int MAXN = 1e5 + 1;
ll dp[MAXN];
ll m = 1e9 + 7;

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t, k;
    cin >> t >> k;
    dp[0] = 1;
    for (ll i = 1; i < MAXN; i++)
    {
        dp[i] = dp[i - 1];
        if (i - k >= 0)
            (dp[i] += dp[i - k] % m) %= m;
    }
    for (ll i = 1; i < MAXN; i++)
    {
        (dp[i] += dp[i - 1] % m) %= m;
    }
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + m) % m << nl;
    }
    return 0;
}