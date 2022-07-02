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
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> val(30, 0);
        for (ll i = 0; i < n; i++)
        {
            ll res = 0;
            ll num = 1;
            for (ll j = 0; j < 30; j++)
            {
                ll q = a[i] & num;
                if (val[j] && !q)
                {
                    res += num;
                }
                num *= 2;
            }
            num = 1;
            a[i] += res;
            for (ll j = 0; j < 30; j++)
            {
                if (num & a[i])
                    val[j] = 1;
                else
                {
                    val[j] = 0;
                }
                num *= 2;
            }
            cout << res << " ";
        }
        cout << nl;
    }
    return 0;
}