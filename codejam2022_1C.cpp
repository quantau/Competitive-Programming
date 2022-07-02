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

bool check(string str)
{
    ll m = str.size();
    vector<ll> freq(26, 0);
    for (ll i = 0; i < m; i++)
    {
        if (!freq[str[i] - 'A'] || (str[i] == str[i - 1]))
        {
            freq[str[i] - 'A']++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++)
    {
        ll n;
        cin >> n;
        string s[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        for (ll i = 0; i < n; i++)
        {
            if (!check(s[i]))
            {
                cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
                return;
            }
        }

        vector<pair<char, char>> v;
        map<char, string> mp;
        map<char, string> mp2;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                string str1 = "", str2 = "";
                str1 += s[i], str1 += s[j];
                str2 += s[j], str2 += s[i];
                if (!check(str1) && !check(str2))
                {
                    cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
                    return;
                }
            }
            char c1 = s[i][0];
            char c2 = s[i][s[i].size() - 1];
            if (c1 == c2)
            {
                mp2[c1] += s[i];
                continue;
            }
            v.pb({c1, c2});
            mp[c1] = s[i];
        }

        string res = "";
        res += mp[v[0].ff];
        ll m = v.size();
        vector<bool> vis(m, 0);
        vis[0] = true;

        for (ll i = 1; i < m; i++)
        {
            bool b1 = false;
            if(mp2.count(res.back())
            {
                b1 = false;
                i++;
                res += mp2[res.back()];                
            }
            bool b = false;
            for (ll j = 0; j < m; j++)
            {
                if (!vis[j] && res.back() == v[j].ff)
                {
                    b = true;
                    res += mp[v[j].ff];
                    vis[j] = true;
                    i++;
                }
            }
            if (!b && !b1)
            {
                for (ll j = 0; j < m; j++)
                {
                    if (!vis[j])
                    {
                        res += mp[v[j].ff];
                        vis[j] = true;
                        i++;
                        break;
                    }
                }
            }
            i--;
        }
        cout << "Case #" << tc << ": " << res << endl;
    }
    return 0;
}