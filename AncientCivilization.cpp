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
        ll n, l;
        cin >> n >> l;
        vector<ll> c(l + 1, 0);
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            ll num;
            cin >> num;
            ll pow = 1;
            for (ll j = 0; j < l; j++)
            {
                if ((pow & num))
                {
                    c[j]++;
                }
                pow *= 2;
            }
        }
        ll num = 1;
        for (ll i = 0; i < l; i++)
        {
            if (c[i] > n / 2)
            {
                res += num;
            }
            num *= 2;
        }
        cout << res << nl;
    }
    return 0;
}