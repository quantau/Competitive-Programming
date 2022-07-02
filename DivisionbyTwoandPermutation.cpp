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
    vector<ll> a(n);
    vector<bool> vis(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(rall(a));
    for (ll i = 0; i < n; i++)
    {
        ll num = a[i];
        while (num > 0)
        {
            if (num <= n)
            {
                if (!vis[num])
                {
                    vis[num] = true;
                    break;
                }
            }
            num /= 2;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i + 1])
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