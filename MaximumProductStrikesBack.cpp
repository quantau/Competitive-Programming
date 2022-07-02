#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

void solve(vector<ll> &v, ll &res, pii &p, bool chk)
{
    ll m = v.size();
    ll val = 0;
    ll parity = 0;
    ll j = 0;
    for (ll i = 0; i < m; i++)
    {
        if (v[i])
        {
            val += (abs(v[i]) == 2);
            parity += (v[i] < 0);
            if (parity % 2 == 0 && val > res)
            {
                res = val;
                if (chk)
                {
                    p = {m - 1 - i, m - 1 - j};
                    // var(p.ff, p.ss, val, chk);
                }
                else
                {
                    p = {j, i};
                    // var(i, j, val, chk);
                }
            }
        }
        else
        {
            j = i + 1;
            val = 0;
            parity = 0;
        }
    }
    // cout << nl;
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v;
        vector<ll> vec;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            vec.pb(a);
            if (a == 1)
                continue;
            else
                v.pb(a);
        }
        ll m = v.size();
        bool b = false;
        for (ll i = 0; i < m; i++)
        {
            if (v[i] > 0)
                b = true;
            else if (v[i] == -2)
            {
                if (i && v[i - 1])
                    b = true;
                if (i + 1 < m && v[i + 1])
                    b = true;
            }
        }
        if (!b)
        {
            cout << n << " " << 0 << nl;
            continue;
        }

        ll res = 0;
        pii p;
        solve(vec, res, p, 0);
        reverse(all(vec));
        solve(vec, res, p, 1);
        cout << p.ff << " " << n - 1 - p.ss << nl;
    }
    return 0;
}