#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
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

const int inf = 1e9 + 7;

int main()
{
    FASTIO

    string s;
    cin >> s;
    ll n = s.size();
    ll p[26][26];
    int res = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            p[i][j] = 0;
        }
    }

    bool pres[26] = {0};
    int mp[26];
    for (int i = 1; i < n; i++)
    {
        p[s[i - 1] - 'a'][s[i] - 'a']++;
        pres[s[i] - 'a'] = 1;
        pres[s[i - 1] - 'a'] = 1;
    }

    int x = 0;
    for (int i = 0; i < 26; i++)
    {
        res += p[i][i];
        if (pres[i])
        {
            mp[x] = i;
            x++;
        }
    }

    ll dp[(1 << x)];

    for (int i = 0; i < (1 << x); i++)
    {
        dp[i] = inf;
    }

    for (int i = 0; i < x; i++)
    {
        dp[1 << i] = 1;
    }
    dp[0] = 1;

    for (int i = 0; i < (1 << x); i++)
    {
        // dbg(i);
        for (int j = 0; j < x; j++)
        {
            if (!(i & (1 << j)))
            {
                ll val = 0;
                for (int k = 0; k < x; k++)
                {
                    if (i & (1 << k))
                    {
                        val += p[mp[j]][mp[k]];
                    }
                }
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + val);
            }
        }
    }

    // for (int i = 0; i < (1 << x); i++)
    // {
    //     cout << dp[i] << " ";
    // }
    // cout << nl;

    cout << res + dp[(1 << x) - 1] << nl;

    return 0;
}