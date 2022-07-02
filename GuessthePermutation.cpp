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

ll query(ll l, ll r)
{
    cout << "? " << l << " " << r << endl;
    ll reply;
    cin >> reply;
    return reply;
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
        ll n;
        cin >> n;
        ll sum = query(1, n);
        ll lo = 1, hi = n;
        ll k = n + 1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (query(1, mid) == sum)
            {
                k = min(k, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        ll j = k - (query(1, k) - query(1, k - 1));
        ll i = j - 1 - (query(1, j - 1) - query(1, j - 2));
        cout << "! " << i << " " << j << " " << k << endl;
    }
    return 0;
}