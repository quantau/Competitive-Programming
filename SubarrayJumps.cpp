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
        ll n;
        cin >> n;
        ll a[n];
        cin >> a[0];
        ll res = a[0];
        ll num = a[0];
        for (ll i = 1; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > num)
            {
                res += num;
            }
            else
            {
                res += num;
                num = a[i];
            }
        }
        res -= a[n - 1];
        ll zero = 0;
        cout << max(zero, res) << nl;
    }
    return 0;
}