//I printf my destiny

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

ll a[26], o[26];

bool compare(ll i, ll j)
{
    if (a[i] != a[j])
        return a[i] > a[j];
    return i < j;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("capastaty_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        string s;
        cin >> n >> k >> s;
        vector<ll> v[26];
        for (ll i = 0; i < 26; i++)
        {
            cin >> a[i];
            o[i] = i;
        }
        sort(o, o + 26, compare);
        // for (ll i = 0; i < 26; i++)
        // {
        //     cout << o[i] << " ";
        // }
        // cout << nl;
        for (ll i = 0; i < n; i++)
        {
            v[s[i] - 'a'].pb(i);
        }
        set<ll> r;
        for (ll i = 0; i < 26; i++)
        {
            ll m = v[o[i]].size();
            for (ll j = 0; j < m; j++)
            {
                if (m - j <= k)
                {
                    r.insert(v[o[i]][j]);
                    k--;
                }
                else if (k)
                {
                    auto it = r.upper_bound(v[o[i]][j]);
                    if (it == r.end() || s[*it] - 'a' > o[i])
                    {
                        k--;
                        r.insert(v[o[i]][j]);
                    }
                }
            }
        }
        for (auto x : r)
        {
            cout << s[x];
        }
        cout << nl;
    }
    return 0;
}