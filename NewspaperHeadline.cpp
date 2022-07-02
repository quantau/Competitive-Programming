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

    string s, t;
    cin >> s >> t;
    map<char, set<ll>> mp;
    ll n = s.size(), m = t.size();
    for (ll i = 0; i < n; i++)
    {
        mp[s[i]].insert(i);
    }
    ll res = 0, j = -1;
    for (ll i = 0; i < m; i++)
    {
        if (mp[t[i]].empty())
        {
            res = -2;
            break;
        }
        auto it = mp[t[i]].upper_bound(j);
        if (it == mp[t[i]].end())
        {
            res++;
            j = -1;
            i--;
        }
        else
        {
            j = *it;
        }
    }
    cout << res + 1 << nl;
    return 0;
}