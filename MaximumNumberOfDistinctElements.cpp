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
        vector<pii> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i].ff;
            v[i].ss = i;
        }
        sort(all(v));
        ll r[n];
        ll num = 0, val = 0;
        for (ll i = 0; i < n; i++)
        {
            if (v[i].ff - val <= 0)
            {
                r[v[i].ss] = 0;
                val--;
            }
            else
            {
                r[v[i].ss] = num;
                num++;
            }
            val++;
        }
        for (ll i = 0; i < n; i++)
        {
            cout << r[i] << " ";
        }
        cout << nl;
    }
    return 0;
}