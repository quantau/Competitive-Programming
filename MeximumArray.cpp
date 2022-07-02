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
        vector<bool> pres(n + 2, 0);
        vector<ll> mex(n + 1);
        ll j = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            pres[a[i]] = 1;
            while (pres[j])
                j++;
            mex[i] = j;
        }
        for (ll i = 0; i <= n + 1; i++)
        {
            pres[i] = false;
        }
        j = 0;
        ll mx = 0;
        vector<ll> r;
        for (ll i = 0; i < n; i++)
        {
            pres[a[i]] = 1;
            while (pres[mx])
                mx++;
            if (mx == mex[j])
            {
                r.pb(mx);
                mx = 0;
                for (ll k = j; k <= i; k++)
                {
                    pres[a[k]] = 0;
                }
                j = i + 1;
            }
        }
        cout << r.size() << nl;
        for (auto x : r)
            cout << x << " ";
        cout << nl;
    }
    return 0;
}