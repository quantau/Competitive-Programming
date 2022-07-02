//░░░░░░░░░░
//░░░░░░░░▄▐░▄▄█████▄▄
//░░░░░░▄█████████████▄▀▄▄▄▄▄
//░░░░░█████████████████▄██████
//░░░░████▐█████▌████████▌█████▌
//░░░████▌█████▌█░████████▐▀██▀
//░▄█████░█████▌░█░▀██████▌█▄▄▀▄
//░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀
//▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█
//░░███░▌▄█▌░░▀░░▀██░░▀██████▌
//░░░▀█▌▀██▀░▄░░░░░░░░░███▐███
//░░░░██▌░░░░░░░░░░░░░▐███████▌
//░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌
//░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀
//░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░▀
//░░░░░░░░░▀░▀█▀▌▒▒▒░▐▄▄
//░░░░░░░░▄▄▀▀▄░░░░░░▄▀░▀▀▄▄
//░░░░░░▄▀░▄▀▄░▌░░░▄▀░░░░░░▄▀▀▄
//░░░░░▐▒▄▀▄▀░▌▀▄▄▀░░░░░░▄▀▒▒▒▐
//░░░░▐▒▒▌▀▄░░░░░▌░░░░▄▄▀▒▐▒▒▒▒▌
//░░░▐▒▒▐░▌░▀▄░░▄▀▀▄▀▀▒▌▒▐▒▒▒▒▐▐
//░░░▌▄▀░░░▄▀░█▀▒▒▒▒▀▄▒▌▐▒▒▒▒▒▌▌
//░░▄▀▒▐░▄▀░░░▌▒▐▒▐▒▒▒▌▀▒▒▒▒▒▐▒▌
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

ll dp[MAXN][2];
ll inf = 1e16 + 7;

bool check(string s, string t, ll n, ll m)
{
    for (ll i = 0; i < n; i++)
    {
        if (t[i] < s[i])
            return false;
        if (t[i] > s[i])
            return true;
    }
    return n <= m;
}

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
    ll c[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    string s[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (ll i = 1; i < n; i++)
    {
        dp[i][0] = inf;
        dp[i][1] = inf;
        ll X = s[i - 1].size();
        ll Y = s[i].size();
        string t1 = s[i];
        string t2 = s[i - 1];
        reverse(all(t1));
        reverse(all(t2));
        if (check(s[i - 1], s[i], X, Y))
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (check(t2, s[i], X, Y))
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (check(s[i - 1], t1, X, Y))
        {
            dp[i][1] = min(dp[i - 1][0] + c[i], dp[i][1]);
        }
        if (check(t2, t1, X, Y))
        {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        }
    }
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << (ans >= inf ? -1 : ans) << nl;
    return 0;
}