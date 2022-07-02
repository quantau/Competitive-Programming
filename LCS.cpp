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

    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();
    ll dp[n + 1][m + 1];
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            dp[i][j] = max({dp[i - 1][j - 1] + (s[i - 1] == t[j - 1]), dp[i - 1][j], dp[i][j - 1]});
        }
    }
    string res = "";
    ll i = n, j = m;
    while (dp[i][j] != 0)
    {
        if (dp[i - 1][j] == dp[i][j])
        {
            i--;
        }
        else if (dp[i][j - 1] == dp[i][j])
        {
            j--;
        }
        else
        {
            i--, j--;
            res += s[i];
        }
    }
    reverse(all(res));
    cout << res << nl;
    return 0;
}