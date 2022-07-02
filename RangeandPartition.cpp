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

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        vector<ll> b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(all(b));
        ll ans = n - 1;
        pii p = {1, n};
        for (ll i = 1; i <= n; i++)
        {
            ll lo = i, hi = n;
            ll res = hi + 1;
            while (lo <= hi)
            {
                ll mid = (lo + hi) / 2;
                ll val = upper_bound(all(b), mid) - lower_bound(all(b), i);
                if (2 * val >= n + k)
                {
                    res = min(res, mid);
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            if (res <= n && res - i < ans)
            {
                ans = res - i;
                p = {i, res};
            }
        }
        cout << p.ff << " " << p.ss << nl;
        ll l = 0, r = 0, sum = 0;
        ll subsets = 0;
        for (r = 0; r < n; r++)
        {
            if (subsets == k - 1)
                break;
            if (a[r] >= p.ff && a[r] <= p.ss)
                sum++;
            else
                sum--;
            if (sum > 0)
            {
                cout << l + 1 << " " << r + 1 << nl;
                l = r + 1;
                sum = 0;
                subsets++;
            }
        }
        cout << r + 1 << " " << n << nl;
    }
    return 0;
}