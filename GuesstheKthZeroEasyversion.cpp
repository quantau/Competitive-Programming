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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, t, k;
    cin >> n >> t >> k;
    ll lo = 1, hi = n;
    ll res = hi + 1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        cout << "? " << lo << " " << mid << endl;
        ll count;
        cin >> count;
        count = mid - lo + 1 - count;
        if (count >= k)
        {
            hi = mid - 1;
            res = min(res, mid);
        }
        else
        {
            k -= count;
            lo = mid + 1;
        }
    }
    cout << "! " << res << endl;
    return 0;
}