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

    ll n;
    cin >> n;
    map<ll, vector<ll>> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x].pb(i);
    }
    ll res = 0;
    vector<pii> v;
    for (auto x : mp)
    {
        if (x.ss.size() == 1)
        {
            res++;
            v.pb({x.ff, 0});
            continue;
        }
        bool b = true;
        ll d = x.ss[1] - x.ss[0];
        for (ll i = 1; i < x.ss.size(); i++)
        {
            if (d != x.ss[i] - x.ss[i - 1])
            {
                b = false;
                break;
            }
        }
        if (b)
        {
            v.pb({x.ff, d});
        }
    }
    cout << v.size() << nl;
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i].ff << " " << v[i].ss << nl;
    }
    return 0;
}