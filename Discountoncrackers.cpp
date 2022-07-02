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
ll inf = 1e9 + 7;

void solve()
{
    string s, t;
    cin >> s >> t;
    ll m;
    cin >> m;
    ll a[27][27];
    for (ll i = 0; i < 27; i++)
    {
        for (ll j = 0; j < 27; j++)
        {
            a[i][j] = inf;
        }
        a[i][i] = 0;
    }
    for (ll i = 0; i < m; i++)
    {
        char x, x1, y1, y;
        cin >> x >> x1 >> y1 >> y;
        a[x - 'a' + 1][y - 'a' + 1] = 1;
        //a[y - 'a' + 1][x - 'a' + 1] = 1;
    }
    for (ll k = 1; k <= 26; k++)
    {
        for (ll i = 1; i <= 26; i++)
        {
            for (ll j = 1; j <= 26; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    if (s.size() != t.size())
    {
        cout << "NO\n";
        return;
    }
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            if (a[s[i] - 'a' + 1][t[i] - 'a' + 1] == inf)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
        solve();
    }
    return 0;
}
