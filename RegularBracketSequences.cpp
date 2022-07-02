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
        vector<char> s, t;
        for (ll i = 0; i < n; i++)
        {
            s.pb('(');
        }
        for (ll i = 0; i < n; i++)
        {
            s.pb(')');
        }
        for (ll i = 0; i < n; i++)
        {
            ll j = 0;
            ll val1 = 0;
            ll val2 = 0;
            while (j < 2 * n)
            {
                if (j % 2 && val1 < t.size())
                {
                    cout << t[val1];
                    val1++;
                }
                else
                {
                    cout << s[val2];
                    val2++;
                }
                j++;
            }
            cout << nl;
            t.pb(')');
            s.pop_back();
        }
    }
    return 0;
}