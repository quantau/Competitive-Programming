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

ll box;
bool cust(pii a, pii b)
{
    if (a.ff / box == b.ff / box)
    {
        return a.ss < b.ss;
    }
    return a.ff / box < b.ff / box;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, q;
    cin >> n >> q;
    ll a[n];
    map<ll, ll> key;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        key[a[i]] = 1;
    }
    ll count = 0;
    for (auto &x : key)
    {
        x.ss = count++;
    }
    for (ll i = 0; i < n; i++)
    {
        a[i] = key[a[i]];
    }
    vector<pii> v(q), vec(q);
    for (ll i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        v[i] = {x, y};
        vec[i] = {x, y};
    }
    box = q / sqrt(n);
    sort(all(v), cust);

    ll strt = v[0].ff, end = v[0].ff;
    ll res = 1;
    vector<ll> freq(count + 1, 0);
    freq[a[strt]]++;
    map<pii, ll> ans;
    for (ll i = 0; i < q; i++)
    {
        ll l = v[i].ff, r = v[i].ss;
        while (strt < l)
        {
            freq[a[strt]]--;
            if (!freq[a[strt]])
                res--;
            strt++;
        }
        while (strt > l)
        {
            strt--;
            if (!freq[a[strt]])
                res++;
            freq[a[strt]]++;
        }
        while (end > r)
        {
            freq[a[end]]--;
            if (!freq[a[end]])
                res--;
            end--;
        }
        while (end < r)
        {
            end++;
            if (!freq[a[end]])
                res++;
            freq[a[end]]++;
        }
        ans[v[i]] = res;
    }
    for (ll i = 0; i < q; i++)
    {
        cout << ans[vec[i]] << nl;
    }
    return 0;
}