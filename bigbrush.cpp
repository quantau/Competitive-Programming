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

ll a[1001][1001];
ll dx[3] = {0, -1, -1};
ll dy[3] = {-1, 0, -1};
ll n, m;

ll dxx[4] = {0, 1, 0, 1};
ll dyy[4] = {0, 0, 1, 1};
queue<pii> q;
set<pii> st;
vector<pair<pii, ll>> res;

void edit(ll x1, ll y1)
{
    st.insert({x1, y1});
    ll col = 0;
    for (ll i = 0; i < 4; i++)
    {
        ll x = x1 + dxx[i];
        ll y = y1 + dyy[i];
        col = max(col, a[x][y]);
        a[x][y] = 0;
        // var(x, y, -1);
        q.push({x, y});
    }
    res.pb({{x1, y1}, col});
}

bool check(ll x1, ll y1)
{
    set<ll> s;
    for (ll i = 0; i < 4; i++)
    {
        ll x = x1 + dxx[i];
        ll y = y1 + dyy[i];
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if (a[x][y])
        {
            s.insert(a[x][y]);
        }
    }
    return (s.size() == 1);
}

void potents(ll x1, ll y1)
{
    for (ll i = 0; i < 3; i++)
    {
        ll x = x1 + dx[i];
        ll y = y1 + dy[i];
        if (x >= 0 && x < n && y >= 0 && y <= m)
        {
            if (check(x, y) && st.find({x, y}) == st.end())
            {
                edit(x, y);
            }
        }
    }
}

int main()
{
    FASTIO
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (check(i, j))
            {
                edit(i, j);
                // var(i, j, 0);
                // for (ll ii = 0; ii < n; ii++)
                // {
                //     for (ll jj = 0; jj < m; jj++)
                //     {
                //         cout << a[ii][jj] << " ";
                //     }
                //     cout << endl;
                // }
            }
        }
    }
    // ll num = 0;
    while (!q.empty())
    {
        // num++;
        pii node = q.front();
        q.pop();
        ll i = node.ff, j = node.ss;
        // var(i, j, -2);
        potents(i, j);
        // if (num == 25)
        //     break;
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (a[i][j])
            {
                cout << -1 << nl;
                return 0;
            }
        }
    }
    reverse(all(res));
    cout << res.size() << nl;
    for (ll i = 0; i < res.size(); i++)
    {
        cout << res[i].ff.ff + 1 << " " << res[i].ff.ss + 1 << " " << res[i].ss << nl;
    }
    return 0;
}