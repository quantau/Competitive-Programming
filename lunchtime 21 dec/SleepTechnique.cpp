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
        ll a, b;
        cin >> a >> b;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll l, r;
            cin >> l >> r;
            mp[l - 1]--;
            mp[r]++;
        }
        ll val = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            (*it).ss += val;
            val = (*it).ss;
        }
        // for (auto x : mp)
        // {
        //     cout << x.ff << " " << x.ss << nl;
        // }
        ll time = b * (b + 1) / 2;
        ll ans = 0;
        for (auto x : mp)
        {
            ans = max(ans, x.ss);
            if (time <= x.ff)
            {
                break;
            }
        }
        cout << ans << nl;
    }
    return 0;
}