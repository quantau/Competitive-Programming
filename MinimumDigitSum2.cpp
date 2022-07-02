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

ll getcost(ll base, ll n)
{
    ll res = 0;
    while (n)
    {
        res += n % base;
        n /= base;
    }
    return res;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int q;
    cin >> q;
    while (q--)
    {
        ll n, l, r;
        cin >> n >> r;
        pii res;
        l = 2;
        if (n < l)
        {
            cout << l << nl;
            continue;
        }
        else if (n <= r)
        {
            cout << n << nl;
            continue;
        }
        ll sqrt_n = sqrt(n);
        res = {getcost(r, n), r};
        for (int i = l; i <= min(sqrt_n + 1, r); i++)
        {
            ll cost = getcost(i, n);
            if (cost < res.ff)
            {
                res.ff = cost;
                res.ss = i;
            }
        }
        for (ll i = 1; i <= sqrt_n + 2; i++)
        {
            ll d = n / i;
            if (d < l)
            {
                d = l;
            }
            else if (d > r)
            {
                d = r;
            }
            ll cost = getcost(d, n);
            if (cost < res.ff)
            {
                res = {cost, d};
            }
        }
        cout << res.ss << nl;
    }
    return 0;
}