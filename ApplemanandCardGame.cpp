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

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(26, 0);
    for (ll i = 0; i < n; i++)
    {
        v[s[i] - 'A']++;
    }
    sort(all(v));
    // for (auto x : v)
    // {
    //     cout << x << " ";
    // }
    // cout << nl;
    ll res = 0;
    while (k)
    {
        ll x = v.back();
        v.pop_back();
        if (x > k)
        {
            res += k * k;
            k = 0;
        }
        else
        {
            res += x * x;
            k -= x;
        }
        // var(x, k, res);
    }
    cout << res << nl;
    return 0;
}