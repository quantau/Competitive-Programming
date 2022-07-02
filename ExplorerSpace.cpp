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

const ll inf = 1e17 + 7;

int main()
{
    FASTIO

    ll n, m, k;
    cin >> n >> m >> k;

    ll a[n][m];
    ll b[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m - 1; j++)
        {
            cin >> a[i][j];
        }
    }

    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    if (k % 2)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cout << -1 << " ";
            }
            cout << nl;
        }
        return 0;
    }

    k = k / 2 + 1;
    ll dp[n][m][k];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            for (ll l = 0; l < k; l++)
            {
                dp[i][j][l] = inf;
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for (ll l = 1; l < k; l++)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j + 1 < m; j++)
            {
                dp[i][j][l] = min(dp[i][j][l], dp[i][j + 1][l - 1] + a[i][j]);
                dp[i][j + 1][l] = min(dp[i][j + 1][l], dp[i][j][l - 1] + a[i][j]);
            }
        }

        for (ll i = 0; i + 1 < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                dp[i][j][l] = min(dp[i][j][l], dp[i + 1][j][l - 1] + b[i][j]);
                dp[i + 1][j][l] = min(dp[i + 1][j][l], dp[i][j][l - 1] + b[i][j]);
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << 2 * dp[i][j][k - 1] << " ";
        }
        cout << nl;
    }

    return 0;
}