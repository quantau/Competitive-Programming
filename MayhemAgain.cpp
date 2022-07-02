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

ll n, m;
ll a[1001][1001];
bool vis[1001][1001];
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {1, -1, 0, 0};

void dfs(ll x1, ll y1, ll val, ll &cnt)
{
    vis[x1][y1] = true;
    cnt++;
    for (ll i = 0; i < 4; i++)
    {
        ll x = x1 + dx[i];
        ll y = y1 + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= n)
        {
            continue;
        }
        if (a[x][y] == val && !vis[x][y])
        {
            dfs(x, y, val, cnt);
        }
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll bank, strength = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll cnt = 0;
            if (!vis[i][j])
            {
                //vis[i][j]=true;
                dfs(i, j, a[i][j], cnt);
                //  dbg(cnt);
                if (cnt > strength)
                {
                    //var(a[i][j], strength, cnt);
                    bank = a[i][j];
                    strength = cnt;
                }
                else if (cnt == strength && bank > a[i][j])
                {
                    bank = a[i][j];
                }
            }
        }
    }
    cout << bank << " " << strength << nl;
    return 0;
}