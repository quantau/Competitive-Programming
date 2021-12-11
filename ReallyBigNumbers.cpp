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

bool ok(ll x, ll s)
{
    ll num = x;
    ll res = 0;
    while (num)
    {
        res += num % 10;
        num /= 10;
    }
    return (x - res) >= s;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, s;
    cin >> n >> s;
    ll lo = 1, hi = n;
    ll res = n + 1;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid, s))
        {
            res = min(res, mid);
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << (res == n + 1 ? 0 : n - res + 1) << nl;
    return 0;
}