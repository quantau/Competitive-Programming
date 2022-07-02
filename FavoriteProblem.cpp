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

void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll f[2][3] = {0};
    string s1 = "", s2 = "";
    for (ll i = 0; i < n; i++)
    {
        f[0][s[i] - 'a']++;
        f[1][t[i] - 'a']++;
        if (s[i] != 'b')
            s1 += s[i];
        if (t[i] != 'b')
            s2 += t[i];
    }
    if (s1 != s2 || f[0][0] != f[1][0] || f[0][1] != f[1][1] || f[0][2] != f[1][2])
    {
        // var(s1, s2, -1);
        cout << "NO\n";
        return;
    }
    ll cont[2] = {0};
    vector<ll> v[2];
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            cont[0]++;
        else
            v[0].pb(cont[0]);
        if (t[i] == 'b')
            cont[1]++;
        else
            v[1].pb(cont[1]);
    }
    ll m = v[0].size();
    for (ll i = 0; i < m; i++)  
    {
        if (s1[i] == 'a' && v[0][i] > v[1][i])
        {
            cout << "NO\n";
            return;
        }
        else if (s1[i] == 'c' && v[0][i] < v[1][i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}