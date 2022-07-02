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

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        //part 1
        ll cost = 0;
        for (ll i = 1; i < n; i += 2)
        {
            if (s[i] != s[i - 1])
            {
                cost++;
            }
        }

        //part 2
        ll dp[n][2];
        ll inf = 1e16;
        for (ll i = 0; i < n; i++)
        {
            dp[i][0] = inf;
            dp[i][1] = inf;
        }
        for (ll i = 1; i < n; i += 2)
        {
            ll x = s[i] - '0';
            ll y = 1 - x;
            if (s[i] == s[i - 1])
            {
                if (i == 1)
                {
                    dp[i][x] = 1;
                    dp[i][y] = inf;
                }
                else
                {
                    dp[i][x] = min(dp[i - 2][x], dp[i - 2][y] + 1);
                    dp[i][y] = inf;
                }
            }
            else
            {
                if (i == 1)
                {
                    dp[i][0] = 1;
                    dp[i][1] = 1;
                }
                else
                {
                    dp[i][0] = min(dp[i - 2][0], dp[i - 2][1] + 1);
                    dp[i][1] = min(dp[i - 2][1], dp[i - 2][0] + 1);
                }
            }
        }
        cout << cost << " " << min(dp[n - 1][0], dp[n - 1][1]) << nl;
    }
    return 0;
}