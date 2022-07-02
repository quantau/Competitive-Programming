#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll short int
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

ll n;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
char dc[4] = {'L', 'R', 'U', 'D'};
char cd[4] = {'R', 'L', 'D', 'U'};
ll a[2][1005][1005];
char c[1005][1005];
queue<pii> q;

void bfs()
{
    while (!q.empty())
    {
        pii p = q.front();
        ll i = p.ff, j = p.ss;
        q.pop();
        for (ll l = 0; l < 4; l++)
        {
            ll x = p.ff + dx[l];
            ll y = p.ss + dy[l];
            if (x <= 0 || x > n || y <= 0 || y > n || a[0][x][y] != a[0][i][j] || a[1][x][y] != a[1][i][j])
                continue;
            if (c[x][y] == '\0')
            {
                c[x][y] = dc[l];
                q.push({x, y});
            }
        }
    }
}

int main()
{
    FASTIO
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[0][i][j] >> a[1][i][j];
            if (a[0][i][j] == i && a[1][i][j] == j)
            {
                c[i][j] = 'X';
                q.push({i, j});
            }
        }
    }
    bfs();
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (a[0][i][j] > 0)
                continue;
            for (ll k = 0; k < 4; k++)
            {
                ll x = i + dx[k];
                ll y = j + dy[k];
                if (x <= 0 || x > n || y <= 0 || y > n || a[0][x][y] != a[0][i][j] || a[1][x][y] != a[1][i][j])
                    continue;
                c[i][j] = cd[k];
                break;
            }
            if (c[i][j] == '\0')
            {
                cout << "INVALID\n";
                return 0;
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            if (c[i][j] == '\0')
            {
                cout << "INVALID\n";
                return 0;
            }
        }
    }
    cout << "VALID\n";
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            cout << c[i][j];
        }
        cout << nl;
    }
    return 0;
}