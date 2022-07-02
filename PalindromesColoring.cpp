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

bool ok(ll x, ll k, ll pair, ll solo)
{
    ll req = (x / 2) * k;
    ll avail = pair - req;
    if (avail < 0)
        return false;
    solo += avail * 2;
    avail = solo - (x % 2) * k;
    if (avail < 0)
        return false;
    return true;
}

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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> c(26, 0);
        for (ll i = 0; i < n; i++)
        {
            c[s[i] - 'a']++;
        }
        ll pairs = 0, solo = 0;
        for (ll i = 0; i < 26; i++)
        {
            if (!c[i])
                continue;
            // cout << c[i] << " ";
            pairs += c[i] / 2;
            solo += c[i] % 2;
        }
        // cout << nl;
        // var(pairs, -1, solo);
        ll lo = 1, hi = n;
        ll res = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if (ok(mid, k, pairs, solo))
            {
                res = max(res, mid);
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << res << nl;
    }
    return 0;
}