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
    ll a[n];
    map<ll, set<ll>> mp;
    vector<ll> v(n + 1, 0);
    vector<ll> vis(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        v[a[i]]++;
        mp[a[i]].insert(i);
    }
    ll ans[n];
    ll col = 1;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (v[a[i]] < n - a[i])
            {
                cout << "Impossible\n";
                return 0;
            }
            v[a[i]] -= n - a[i];
            ll c = n - a[i];
            while (c--)
            {
                auto it = mp[a[i]].begin();
                ans[*it] = col;
                vis[*it] = true;
                mp[a[i]].erase(it);
                it = mp[a[i]].begin();
            }
            col++;
        }
    }
    cout << "Possible\n";
    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << nl;
    return 0;
}