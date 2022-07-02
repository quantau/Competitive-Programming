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
    ll n, m;
    cin >> n >> m;
    string s[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<pii> vec;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (s[i][j] == 'R')
            {
                vec.pb({i, j});
            }
        }
    }
    for (ll i = 0; i < vec.size(); i++)
    {
        bool b = true;
        for (ll j = 0; j < vec.size(); j++)
        {
            if (vec[j].ff >= vec[i].ff && vec[j].ss >= vec[i].ss)
            {
                continue;
            }
            else
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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