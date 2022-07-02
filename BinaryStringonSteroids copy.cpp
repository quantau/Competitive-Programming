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
        string s;
        cin >> s;
        ll sum = 0;
        ll f = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += s[i] - '0';
            if (sum == 1)
            {
                f = i;
            }
        }
        ll res = n;
        for (ll d = 1; d <= n; d++)
        {
            if (n % d)
                continue;
            ll cnt = 0;
            for (ll j = f; j < n; j += d)
            {
                if (s[d] == '1')
                {
                    cnt--;
                }
                else
                {
                    cnt++;
                }
            }
            res = min(res, sum+cnt);
        }
        cout << res << nl;
    }
    return 0;
}