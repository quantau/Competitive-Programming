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
        ll n, m;
        cin >> n >> m;
        vector<pair<ll, string>> v(n);
        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ll one = 0;
            for (ll j = 0; j < m; j++)
            {
                if (s[j] == '1')
                    one++;
            }
            v[i] = {one, s};
        }
        sort(all(v));
        ll one = 0, ans = 0;
        for (ll i = 0; i < n; i++)
        {
            string s = v[i].ss;
            for (ll j = 0; j < m; j++)
            {
                if (s[j] == '1')
                {
                    one++;
                }
                else
                {
                    ans += one;
                }
            }
        }
        cout << ans << nl;
    }
    return 0;
}