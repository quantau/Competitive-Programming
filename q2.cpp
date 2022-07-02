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
        vector<ll> v(35, 0);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            ll num = 1;
            for (ll j = 0; j < 35; j++)
            {
                if (a[i] & num)
                {
                    v[j]++;
                }
                num *= 2;
            }
        }
        ll res = 0;
        ll num = 1;
        for (ll i = 0; i < 35; i++)
        {
            res += (v[i] >= 2 ? num : 0);
            num *= 2;
        }
        cout << res << nl;
    }
    return 0;
}