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

void solve(ll tc)
{
    ll n;
    cin >> n;
    string s[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    map<char, string> mp;
    vector<string> v;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            string str1 = "", str2 = "";
            str1 += s[i], str1 += s[j];
            str2 += s[j], str2 += s[i];
            if (!check(str1) && !check(str2))
            {
                cout << "Case #" << tc << ": IMPOSSIBLE" << nl;
                return;
            }
        }
        char c1 = s[i][0];
        char c2 = s[i][s[i].size() - 1];
        if (c1 == c2)
        {
            mp[c1] += s[i];
            continue;
        }
        else
        {
            v.pb(s[i]);
        }
    }
    // dbg(v.size());
    // for (auto x : v)
    // {
    //     cout << x << nl;
    // }
    // dbg(mp.size());
    // for (auto x : mp)
    // {
    //     cout << x.ff << " " << x.ss << nl;
    // }
    ll m = v.size();
    for (ll i = 0; i < m; i++)
    {
        if (mp.count(v[i].front()))
        {
            v[i] = mp[v[i].front()] + v[i];
            mp.erase(v[i].front());
        }
        if (mp.count(v[i].back()))
        {
            v[i] = v[i] + mp[v[i].back()];
            mp.erase(v[i].back());
        }
    }
    vector<bool> vis(m, 0);
    string res = "";
    for (ll i = 0; i < m; i++)
    {
        if (vis[i])
            continue;
        res += v[i];
        bool b = true;
        while (b)
        {
            b = false;
            for (ll j = 0; j < m; j++)
            {
                if (vis[j])
                    continue;
                if (v[j].front() == res.back())
                {
                    res += v[j];
                    vis[j] = true;
                    b = true;
                }
                if (v[j].back() == res.front())
                {
                    res = v[j] + res;
                    vis[j] = true;
                    b = true;
                }
            }
        }
    }
    for (auto x : mp)
    {
        res += x.ss;
    }
    cout << "Case #" << tc << ": " << res << nl;
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    for (ll tc = 1; tc <= t; tc++)
    {
        solve(tc);
    }
    return 0;
}
