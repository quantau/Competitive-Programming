#include <bits/stdc++.h>
#define sz(x) x.size()
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
// #define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define on_bit(x) __builtin_popcountint(x)
#define msb(x) (63 - __builtin_clzint(x))
#define lsb(x) __builtin_ctzint(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

int dp[5005][5005];

int main()
{
    FASTIO

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i && s[i] == s[i - 1])
            dp[i - 1][i] = 2;
        else if (i)
            dp[i - 1][i] = 0;
    }

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < (n - k + 1); i++)
        {
            int j = i + k - 1;
            dp[i][j] = 0;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = dp[i][(i + j - 1) / 2] + 1;
            }
        }
    }

    int res[n + 5] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            res[dp[i][j]]++;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        res[i] += res[i + 1];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << nl;

    return 0;
}