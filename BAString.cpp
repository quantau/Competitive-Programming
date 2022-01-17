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
        ll n, k, x;
        cin >> n >> k >> x;
        x--;
        string s;
        cin >> s;
        string t = "";
        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                t += 'a';
            }
            else
            {
                t += '*';
                ll cont = 0;
                while (i < n && s[i] == '*')
                {
                    cont++;
                    i++;
                }
                v.pb(k * cont + 1);
                i--;
            }
        }
        reverse(all(v));
        vector<ll> res;
        for (auto z : v)
        {
            res.pb(x % z);
            x /= z;
        }
        reverse(all(res));
        ll j = 0;
        for (auto z : t)
        {
            if (z == 'a')
            {
                cout << 'a';
            }
            else
            {
                while (res[j]--)
                {
                    cout << 'b';
                }
                j++;
            }
        }
        cout << nl;
    }
    return 0;
}