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

    // I\O
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    if (n < m)
    {
        cout << 0 << nl;
        return 0;
    }

    // calculating LPS
    ll lps[m + 5];
    lps[0] = 0;
    ll len = 0;
    ll i = 1;
    while (i < m)
    {
        if (t[i] == t[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    // precalculating max prefix length for given suffix length and next character
    ll next[m + 5][26];
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < 26; j++)
        {
            char c = 'a' + j;
            ll len = i;
            while (len)
            {
                if (t[len] == c)
                {
                    len++;
                    break;
                }
                else if (len)
                {
                    len = lps[len - 1];
                }
            }
            if (len == 0 && t[len] == c)
            {
                len++;
            }
            next[i][j] = len;
        }
    }

    // for(ll i=0;i<)

    ll dp[n + 5][m + 5];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            dp[i][j] = -inf;
        }
    }

    dp[0][0] = 0;
    if (s[0] == '?' || s[0] == t[0])
    {
        dp[0][1] = 0;
    }

    for (ll i = 1; i < n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (s[i] == '?')
            {
                for (ll k = 0; k < 26; k++)
                {
                    ll l = next[j][k];
                    if (j == m)
                    {
                        l = next[lps[j - 1]][k];
                    }
                    dp[i][l] = max(dp[i][l], dp[i - 1][j] + (j == m));
                }
            }
            else
            {
                ll l = next[j][s[i] - 'a'];
                if (j == m)
                {
                    l = next[lps[j - 1]][s[i] - 'a'];
                }
                dp[i][l] = max(dp[i][l], dp[i - 1][j] + (j == m));
            }
        }
    }

    ll res = 0;
    for (int i = 0; i <= m; i++)
    {
        res = max(res, dp[n - 1][i] + (i == m));
    }
    cout << res << nl;
    return 0;
}