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

ll a[17][17];
bool vis[17];
ll n;

ll recurr(ll i)
{
    if (i > 2 * n)
    {
        return 0;
    }
    if (vis[i])
    {
        return recurr(i + 1);
    }
    ll res = 0;
    for (ll j = i + 1; j <= 2 * n; j++)
    {
        if (!vis[j])
        {
            vis[j] = true;
            res = max((a[i][j] ^ recurr(i + 1)), res);
            vis[j] = false;
        }
    }
    return res;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n;
    for (ll i = 1; i <= 2 * n - 1; i++)
    {
        for (ll j = i + 1; j <= 2 * n; j++)
        {
            ll x;
            cin >> x;
            a[i][j] = x;
        }
    }
    cout << recurr(1);
    return 0;
}