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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

const ll inf = 1e9 + 7;

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s[2];
        cin >> s[0] >> s[1];
        ll last = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[0][i] == '*' || s[1][i] == '*')
            {
                last = i;
            }
        }
        ll dp[2][n + 5];
        for (ll i = 0; i <= n; i++)
        {
            dp[0][i] = inf;
            dp[1][i] = inf;
        }
        dp[0][0] = 0, dp[1][0] = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[0][i] == '.' && s[1][i] == '.')
            {
                dp[0][i + 1] = min((dp[0][i] ? dp[0][i] + 1 : 0), (dp[1][i] ? dp[1][i] + 2 : 0));
                dp[1][i + 1] = min((dp[1][i] ? dp[1][i] + 1 : 0), (dp[0][i] ? dp[0][i] + 2 : 0));
            }
            else if (s[0][i] == '*' && s[1][i] == '*')
            {
                dp[0][i + 1] = min(dp[0][i] + 2, dp[1][i] + 2);
                dp[1][i + 1] = min(dp[0][i] + 2, dp[1][i] + 2);
            }
            else
            {
                dp[0][i + 1] = min(dp[0][i] + (s[0][i] == '*' ? 1 : 2), dp[1][i] + 2);
                dp[1][i + 1] = min(dp[1][i] + (s[1][i] == '*' ? 1 : 2), dp[0][i] + 2);
            }
        }
        cout << min(dp[0][last] + (s[1][last] == '*' ? 1 : 0), dp[1][last] + (s[0][last] == '*' ? 1 : 0)) << nl;
    }
    return 0;
}
