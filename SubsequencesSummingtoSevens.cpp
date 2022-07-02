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

    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll mn[7], mx[7];
    for (ll i = 0; i < 7; i++)
    {
        mn[i] = 1e9 + 7, mx[i] = 0;
    }
    ll sm = 0;
    for (ll i = 0; i < n; i++)
    {
        sm += a[i];
        // dbg(sm);
        mn[sm % 7] = min(mn[sm % 7], i);
        mx[sm % 7] = max(i, mx[sm % 7]);
    }
    ll res = 0;
    for (ll i = 0; i < 7; i++)
    {
        // var(mx[i], mn[i], -1);
        res = max(res, mx[i] - mn[i]);
    }
    cout << res << nl;
    return 0;
}