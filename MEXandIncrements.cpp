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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(all(a));
        ll j = 0;
        multiset<ll> s;
        ll ans = 0;
        for (ll i = 0; i <= n; i++)
        {
            ll val = 0;
            ll c = lower_bound(all(a), j) - a.begin();
            // dbg(c);
            if (c < i)
            {
                cout << -1 << " ";
                continue;
            }
            bool b = false;
            while (j < n && a[j] == i)
            {
                // dbg(1);
                if (b)
                {
                    s.insert(-a[j]);
                }
                val++;
                b = true;
                j++;
            }
            cout << ans + val << " ";
            if (!b && !s.empty())
            {
                ans += (*s.begin() + i);
                s.erase(s.begin());
            }
        }
        cout << nl;
    }
    return 0;
}