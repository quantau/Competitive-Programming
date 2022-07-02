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

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    ll n, k, b;
    cin >> n >> k >> b;
    vector<ll> v(n + 1, 0);
    for (ll i = 0; i < b; i++)
    {
        ll pos;
        cin >> pos;
        v[pos]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        v[i] += v[i - 1];
    }
    ll res = n + 1;
    // for (ll i = 0; i <= n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << nl;
    for (ll i = k; i <= n; i++)
    {
        res = min(res, v[i] - v[i - k]);
    }
    cout << res << nl;
    return 0;
}