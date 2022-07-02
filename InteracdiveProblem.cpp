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

ll query(ll x)
{
    cout << "+ " << x << endl;
    ll res;
    cin >> res;
    return res;
}

int main()
{
    //optimization tool
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    ll lo = 1, hi = n;
    while (lo + 1 < hi)
    {
        ll mid = (lo + hi) / 2;
        ll ask = n - (mid % n);
        ll ans = query(ask);
        if (ans > lo / n)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
        lo += ask, hi += ask;
    }
    cout << "! " << lo << endl;
    return 0;
}