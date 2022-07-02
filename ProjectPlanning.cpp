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

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll mx = sum / k;
    ll lo = 0, hi = mx;
    ll res = 0;
    // sort(rall(a));
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll val = 0;
        for (ll i = 0; i < n; i++)
        {
            val += min(mid, a[i]);
        }
        if (val >= mid * k)
        {
            res = max(res, mid);
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << res << nl;
    return 0;
}