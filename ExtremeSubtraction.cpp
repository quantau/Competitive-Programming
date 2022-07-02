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

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll r1[n];
    r1[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        r1[i] = min(r1[i - 1], a[i]);
    }
    ll r2[n];
    r2[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--)
    {
        r2[i] = min(r2[i + 1], a[i]);
    }
    for (ll i = 1; i < n - 1; i++)
    {
        if (a[i] > r1[i - 1] + r2[i + 1])
        {
            cout << "NO\n";
            return;
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