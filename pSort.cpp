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

vector<ll> p(105, -1);

ll get(ll x)
{
    if (p[x] < 0)
        return x;
    p[x] = get(p[x]);
    return p[x];
}

void union_dsu(ll x, ll y)
{
    x = get(x);
    y = get(y);
    if (x == y)
        return;
    if (-p[x] < -p[y])
        swap(x, y);
    p[x] += p[y];
    p[y] = x;
}

bool solve()
{
    ll n;
    cin >> n;
    ll a[n];
    ll d[n];
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        if (i - d[i] > 0)
        {
            union_dsu(i, i - d[i]);
        }
        if (i + d[i] <= n)
        {
            union_dsu(i, i + d[i]);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (get(i) != get(a[i]))
            return false;
    }
    return true;
}
int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    if (solve())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}