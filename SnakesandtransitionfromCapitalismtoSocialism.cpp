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

using namespace std;

ll inf = 1e17;

ll di[8] = {0, 0, -1, 1, 1, 1, -1, -1};
ll dj[8] = {1, -1, 0, 0, 1, -1, -1, 1};
ll a[501][501];
ll d[501][501]; //declare globally

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll mx = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                d[i][j] = inf;
                cin >> a[i][j];
                mx = max(mx, a[i][j]);
            }
        }
        queue<pii> q;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (a[i][j] == mx)
                {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        ll res = 0;
        while (!q.empty())
        {
            pii p = q.front();
            q.pop();
            for (ll i = 0; i < 8; i++)
            {
                if (p.ff + di[i] < 0 || p.ff + di[i] >= n || p.ss + dj[i] < 0 || p.ss + dj[i] >= m)
                    continue;
                ll x = p.ff + di[i];
                ll y = p.ss + dj[i];
                if (a[x][y] < mx)
                {
                    a[x][y] = mx;
                    d[x][y] = d[p.ff][p.ss] + 1;
                    res = max(res, d[x][y]);
                    q.push({x, y});
                }
            }
        }
        cout << res << nl;
    }
    return 0;
}