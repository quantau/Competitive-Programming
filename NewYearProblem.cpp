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

bool ok(ll val, ll n, ll m, set<pii> s[])
{
    // for (ll i = 0; i < n; i++)
    // {
    //     for (auto x : s[i])
    //     {
    //         printf("|| %d %d || ", x.ff, x.ss);
    //     }
    //     cout << nl;
    // }
    set<ll> st;
    bool b = false;
    for (ll i = 0; i < n; i++)
    {
        ll j = 0;
        for (auto x : s[i])
        {
            if (-x.ff >= val)
            {
                if (st.find(x.ss) != st.end())
                {
                    b = true;
                }
                st.insert(x.ss);
                j = 1;
            }
            else
            {
                if (j == 0)
                    return false;
                break;
            }
        }
    }
    // var(b, st.size(), n - 1);
    if (b || st.size() <= n - 1)
    {
        return true;
    }
    return false;
}

int main()
{
    //optimization tool
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m; //m--> shops   n-->friends
        cin >> m >> n;
        set<pii> s[n];
        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                ll x;
                cin >> x;
                s[j].insert({-x, i});
            }
        }
        ll lo = 1, hi = 1e9 + 1;
        ll res = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            // var(lo, mid, hi);
            if (ok(mid, n, m, s))
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