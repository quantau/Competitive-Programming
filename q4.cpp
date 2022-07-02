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

bool ok(ll mean, ll a[], ll n)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += a[i];
    }
    ll mn_moves = 0;
    for (ll i = (n - 1) / 2; i < n; i++)
    {
        if (a[i] >= mean)
            break;
        mn_moves += mean - a[i];
    }
    ll mx_moves = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] >= mean)
            break;
        mx_moves += mean - a[i];
    }
    if (mean * n - sum >= mn_moves && mean * n - sum <= mx_moves)
    {
        return true;
    }
    return false;
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
        ll n, sum = 0;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n);
        ll moves = 0;
        for (ll i = 0; i < n; i++)
        {
            moves += a[(n - 1) / 2] - a[i];
        }
        if (moves >= 0)
        {
            cout << moves << nl;
            continue;
        }
        ll lo = a[(n - 1) / 2], hi = a[n - 1];
        ll res = hi + 1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid, a, n))
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        cout << res * n - sum << nl;
    }
    return 0;
}