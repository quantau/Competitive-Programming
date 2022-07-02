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
        ll n, m;
        cin >> n >> m;
        string s[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        string str;
        cin >> str;
        map<string, ll> mp;
        for (ll i = 0; i < m; i++)
        {
            mp[str.substr(i, 2)] = 1;
            mp[str.substr(i, 3)] = 1;
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (mp[s[i].substr(j, 2)] == 1)
                {
                    mp[s[i].substr(j, 2)] = 2;
                }
                if (mp[s[i].substr(j, 3)] == 1)
                {
                    mp[s[i].substr(j, 3)] = 2;
                }
            }
        }
        ll dp[2][m + 1]; //0-->2    1-->3
        for (ll i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
            dp[1][i] = 0;
        }
        dp[0][0] = 1;
        dp[1][0] = 1;
        for (ll i = 1; i <= m; i++)
        {
            string s1 = str.substr(i - 1, 2);
            string s2 = str.substr(i - 1, 3);
            if (dp[0][i - 1] || dp[1][i - 1])
            {
                if (!dp[0][i] && mp[s1] == 2)
                {
                    dp[0][i] = 1;
                    dp[0][i + 1] = 1;
                }
                if (!dp[1][i] && mp[s2] == 2)
                {
                    dp[1][i] = 1;
                    dp[1][i + 1] = 1;
                    dp[1][i + 1] = 1;
                }
            }
        }
    }
    return 0;
}