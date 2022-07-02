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
        ll n;
        cin >> n;
        map<ll, ll> loc, gain, strt, end;
        map<ll, pair<ll, pii>> mp;
        for (ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (!loc.count(a))
            {
                loc[a] = i;
                gain[a] = 1;
                strt[a] = i;
                end[a] = i;
                if (!mp.count(a) || mp[a].ff < gain[a])
                {
                    mp[a] = {gain[a], {strt[a], end[a]}};
                }
            }
            else
            {
                if (gain[a] > i - loc[a] - 1)
                {
                    gain[a] -= (i - loc[a] - 2);
                    loc[a] = i;
                    end[a] = i;
                    if (!mp.count(a) || mp[a].ff < gain[a])
                    {
                        mp[a] = {gain[a], {strt[a], end[a]}};
                    }
                }
                else
                {
                    if (!mp.count(a) || mp[a].ff < gain[a])
                    {
                        mp[a] = {gain[a], {strt[a], end[a]}};
                    }
                    gain[a] = 1;
                    loc[a] = i;
                    end[a] = i;
                    strt[a] = i;
                }
            }
        }
        ll profit = 0;
        pair<ll, pii> p;
        for (auto x : mp)
        {
            if (x.ss.ff > profit)
            {
                profit = x.ss.ff;
                p = {x.ff, {x.ss.ss}};
            }
        }
        cout << p.ff << " " << p.ss.ff + 1 << " " << p.ss.ss + 1 << nl;
    }
    return 0;
}