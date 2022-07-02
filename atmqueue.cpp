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
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll r[n];
        multiset<pii> s;
        r[0] = 1;
        ll j = 2;
        for (ll i = 1; i < n; i += 2)
        {
            s.insert({-a[i], i});
            if (i < n - 1)
            {
                s.insert({-a[i + 1], i + 1});
            }
            pii p = *s.begin();
            r[p.ss] = j;
            // cout << p.ff << " " << p.ss << nl;
            s.erase(s.begin());
            j++;
        }
        // for (auto x : s)
        // {
        //     cout << x.ff << " " << x.ss << nl;
        // }
        while (!s.empty())
        {
            pii p = *s.begin();
            r[p.ss] = j;
            j++;
            s.erase(s.begin());
        }
        for (ll i = 0; i < n; i++)
        {
            cout << r[i] << " ";
        }
        cout << nl;
    }
    return 0;
}