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

    ll n, m;
    cin >> n >> m;
    ll a[n];
    set<pii> s;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        s.insert({a[i], i + 1});
    }
    while (m--)
    {
        ll in, x;
        cin >> in >> x;
        if (in == 1)
        {
            s.erase({in, a[in]});
            s.insert({in, x});
            a[in] = x;
        }
        else
        {
            auto it = s.lower_bound({x, 0});
            if (it == s.end())
            {
                cout << -1 << nl;
            }
            else
            {
                cout << (*it).ss << nl;
            }
        }
    }
    return 0;
}