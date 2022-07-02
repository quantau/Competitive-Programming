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

const int MAXN = 1e5 + 1;
int a[MAXN];

bool ok(ll r, ll n, ll x, ll y)
{
    multiset<ll> s;
    ll sum = 0;
    for (ll i = 0; i < r; i++)
    {
        if (s.size() < y)
        {
            s.insert(a[i]);
        }
        else if (y)
        {
            if (a[i] > (*s.begin()))
            {
                sum += (*s.begin());
                s.erase(s.begin());
                s.insert(a[i]);
            }
            else
            {
                sum += a[i];
            }
        }
    }
    if (sum <= x)
        return true;
    for (ll i = r; i < n; i++)
    {
        if (s.find(a[i - r]) != s.end())
        {
            s.erase(s.find(a[i - r]));
        }
        else
        {
            sum -= a[i - r];
        }
        if (s.size() < y)
        {
            s.insert(a[i]);
        }
        else if (y)
        {
            if (a[i] > (*s.begin()))
            {
                sum += (*s.begin());
                s.erase(s.begin());
                s.insert(a[i]);
            }
            else
            {
                sum += a[i];
            }
        }
        if (sum <= x)
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
        ll n, x, y;
        cin >> n >> x >> y;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll lo = 0, hi = n + 1;
        ll res = 0;
        while (lo < hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid, n, x, y))
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
    }
    return 0;
}