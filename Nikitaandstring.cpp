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

    string s;
    cin >> s;
    ll n = s.size();
    ll prefa[n];
    ll prefb[n];
    prefa[0] = (s[0] == 'a' ? 1 : 0);
    prefb[0] = (s[0] == 'b' ? 1 : 0);
    for (ll i = 1; i < n; i++)
    {
        prefa[i] = prefa[i - 1] + (s[i] == 'a' ? 1 : 0);
        prefb[i] = prefb[i - 1] + (s[i] == 'b' ? 1 : 0);
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << prefa[i] << " ";
    // }
    // cout << nl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << prefb[i] << " ";
    // }
    // cout << nl;
    ll ans = n;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            ll res = 0;
            if (i + j <= n)
            {
                res += (i == 0 ? 0 : prefb[i - 1]);
                //cout << res << " " << prefb[i - 1] << " ";
                res += (j == n ? 0 : prefa[n - j - 1] - (i == 0 ? 0 : prefa[i - 1]));
                //cout << res << " ";
                res += prefb[n - 1] - (j == n ? 0 : prefb[n - j - 1]);
            }
            else
            {
                res = n + 1;
            }
            //var(res, i, j);
            ans = min(ans, res);
        }
    }
    cout << n - ans << nl;
    return 0;
}