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

//efficient way to find gcd
ll get_gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return get_gcd(b, a % b);
    }
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll x[n], d[m];
    for (ll i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    ll g = 0;
    for (ll i = 1; i < n; i++)
    {
        g = get_gcd(g, x[i] - x[i - 1]);
    }
    for (ll i = 0; i < m; i++)
    {
        if (g % d[i] == 0)
        {
            cout << "YES\n";
            cout << x[0] << " " << i + 1 << nl;
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    solve();
    return 0;
}