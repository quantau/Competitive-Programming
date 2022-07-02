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
        vector<ll> v;
        ll num = n;
        while (num)
        {
            v.pb(num % 10);
            num /= 10;
        }
        ll m = v.size();
        ll res = m;
        for (ll i = 0; i < m; i++)
        {
            if (v[i] == 5)
            {
                for (ll j = i + 1; j < m; j++)
                {
                    if (v[j] == 2)
                    {
                        res = min(res, j - 1);
                    }
                    if (v[j] == 7)
                    {
                        res = min(res, j - 1);
                    }
                }
            }
        }
        for (ll i = 0; i < m; i++)
        {
            if (v[i] == 0)
            {
                for (ll j = i + 1; j < m; j++)
                {
                    if (v[j] == 0)
                    {
                        res = min(res, j - 1);
                    }
                    if (v[j] == 5)
                    {
                        res = min(res, j - 1);
                    }
                }
            }
        }
        cout << res << nl;
    }
    return 0;
}