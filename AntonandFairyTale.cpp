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

    ll n, m;
    cin >> n >> m;
    ll lo = 0, hi = 1e10;
    ll res = hi + 1;
    if (m > n)
    {
        cout << n << nl;
        return 0;
    }
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        // var(lo, mid, hi);
        if (m + mid * (mid + 1) / 2 >= n)
        {
            res = min(res, mid);
            // dbg(1);
            hi = mid - 1;
        }
        else
        {
            // dbg(2);
            lo = mid + 1;
        }
    }
    cout << m + res << nl;
    return 0;
}