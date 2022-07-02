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
    ll n, m;
    cin >> n >> m;
    ll a[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }

    ll exitable[n][m];
    vector<ll> res(m, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                exitable[i][j] = 0;
                continue;
            }
            exitable[i][j] = j;
            if (a[i - 1][j])
            {
                exitable[i][j] = min(exitable[i][j], exitable[i - 1][j]);
            }
            if (a[i][j - 1])
            {
                exitable[i][j] = min(exitable[i][j], exitable[i][j - 1]);
            }
            res[j] = max(res[j], exitable[i][j]);
        }
    }
    
    for (ll i = 1; i < m; i++)
    {
        res[i] = max(res[i], res[i - 1]);
    }
    // for (auto x : res)
    // {
    //     cout << x << " ";
    // }
    // cout << nl;
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (res[r - 1] > l - 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}