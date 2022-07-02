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
        vector<ll> v(1, 0);
        ll two = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                v[v.size() - 1]++;
            }
            else if (s[i] == '2')
            {
                two++;
            }
            else
            {
                v.pb(0);
            }
        }
        while (v[0]--)
        {
            cout << 1;
        }
        while (two--)
        {
            cout << 2;
        }
        for (ll i = 1; i < v.size(); i++)
        {
            cout << 3;
            while (v[i]--)
            {
                cout << 1;
            }
        }
        cout << nl;
    }
    return 0;
}