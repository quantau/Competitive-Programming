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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a[i] = 1;
            for (ll j = 0; j < x; j++)
            {
                a[i] *= 10;
            }
        }
        ll c = 0;
        ll num = 0;
        for (ll i = 1; i < n; i++)
        {
            ll c1 = c;
            c += (a[i] / a[i - 1] - 1);
            if (c > k)
            {
                num += a[i - 1] * (k - c1 + 1);
                break;
            }
            num += a[i - 1] * (c - c1);
        }
        if (c <= k)
        {
            num += a[n - 1] * (k - c + 1);
        }
        cout << num << nl;
    }
    return 0;
}