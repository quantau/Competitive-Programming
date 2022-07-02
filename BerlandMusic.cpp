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
        vector<ll> v[2];
        ll a[n];
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]] = i;
        }
        string s;
        cin >> s;
        for (ll i = 0; i < n; i++)
        {
            v[s[i] - '0'].pb(a[i]);
        }
        sort(all(v[0]));
        sort(all(v[1]));
        ll num = 1;
        ll res[n];
        for (ll i = 0; i < v[0].size(); i++)
        {
            res[mp[v[0][i]]] = num;
            num++;
        }
        for (ll i = 0; i < v[1].size(); i++)
        {
            res[mp[v[1][i]]] = num;
            num++;
        }
        for (ll i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << nl;
    }
    return 0;
}