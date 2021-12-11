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

ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};

bool check(ll x, ll y, ll n, ll m, vector<vector<ll>> &a)
{
    ll res = 0;
    for (ll i = 0; i < 4; i++)
    {
        ll x1 = x + dx[i];
        ll y1 = y + dy[i];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == 1)
        {
            res++;
        }
    }
    if (res <= 1)
        return true;
    return false;
}

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
        pii p;
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        queue<pii> q;
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
                else if (c != 'L')
                {
                    a[i][j] = 0;
                }
                else
                {
                    p = {i, j};
                    q.push({i, j});
                    a[i][j] = 2;
                }
            }
        }
        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < m; j++)
        //     {
        //         cout << a[i][j];
        //     }
        //     cout << nl;
        // }

        while (!q.empty())
        {
            ll x = q.front().ff;
            ll y = q.front().ss;
            q.pop();
            a[x][y] = 3;
            for (ll i = 0; i < 4; i++)
            {
                ll x1 = x + dx[i];
                ll y1 = y + dy[i];
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == 1)
                {
                    // var(x1, y1, 0);
                    if (check(x1, y1, n, m, a))
                    {
                        q.push({x1, y1});
                    }
                }
            }
        }
        a[p.ff][p.ss] = 2;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    cout << ".";
                }
                else if (a[i][j] == 2)
                {
                    cout << "L";
                }
                else if (a[i][j] == 3)
                {
                    cout << "+";
                }
                else
                {
                    cout << "#";
                }
            }
            cout << nl;
        }
    }
    return 0;
}