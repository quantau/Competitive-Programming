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
        //Taking input
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 1)
        {
            cout << 0 << nl;
            continue;
        }

        //strong maxima and minima's
        vector<ll> v;
        v.pb(0);
        for (ll i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
                v.pb(i);
            if (a[i] < a[i - 1] && a[i] < a[i + 1])
                v.pb(i);
        }
        v.pb(n - 1);
        ll m = v.size();

        //if following condition is true then answer is always 1
        if (a[0] == 1 && a[n - 1] == n)
        {
            cout << 1 << nl;
            continue;
        }


        map<ll, ll> mp;
        bool increasing = false;
        bool decreasing = false;
        ll mx, mn, mx_loc, mn_loc;
        if (a[v[0]] > a[v[1]])
        {
            decreasing = true;
            mx = a[v[0]];
            mn = a[v[1]];
            mx_loc = 0;
            mn_loc = v[1];
        }
        else
        {
            increasing = true;
            mx = a[v[1]];
            mn = a[v[0]];
            mx_loc = v[1];
            mn_loc = 0;
        }
        ll moves = 0;
        ll curr_loc = 0;
        for (ll i = 2; i < v.size(); i++)
        {
            if (increasing)
            {

                if (a[v[i]] > mx)
                {
                    mx = a[v[i]];
                    mx_loc = v[i];
                }
                else if (a[v[i]] < mn)
                {
                    decreasing = true;
                    increasing = false;
                    moves++;
                    mp[mx_loc] += moves;
                    curr_loc = mx_loc;
                    mn = a[v[i]];
                    mn_loc = v[i];
                }
            }
            else
            {

                if (a[v[i]] < mn)
                {
                    mn = a[v[i]];
                    mn_loc = v[i];
                }
                else if (a[v[i]] > mx)
                {
                    increasing = true;
                    decreasing = false;
                    // var(-i, moves, mn_loc);
                    moves++;
                    mp[mn_loc] += moves;
                    mx = a[v[i]];
                    mx_loc = v[i];
                }
            }
        }
        if (curr_loc != n - 1)
        {
            if (increasing)
            {
                mp[mx_loc] = moves + 1;
            }
            else
            {
                mp[mn_loc] = moves + 1;
            }
        }

        //performing from backside now
        moves = 0;
        increasing = false;
        decreasing = false;
        if (a[v[m - 1]] > a[v[m - 2]])
        {
            decreasing = true;
            mx = a[v[m - 1]];
            mn = a[v[m - 2]];
            mx_loc = v[m - 1];
            mn_loc = v[m - 2];
        }
        else
        {
            increasing = true;
            mx = a[v[m - 2]];
            mn = a[v[m - 1]];
            mx_loc = v[m - 2];
            mn_loc = v[m - 1];
        }
        for (ll i = m - 3; i >= 0; i--)
        {
            if (increasing)
            {
                if (a[v[i]] > mx)
                {
                    mx = a[v[i]];
                    mx_loc = v[i];
                }
                else if (a[v[i]] < mn)
                {
                    decreasing = true;
                    increasing = false;
                    moves++;
                    mp[mx_loc] += moves;
                    mn = a[v[i]];
                    mn_loc = v[i];
                }
            }
            else
            {
                if (a[v[i]] < mn)
                {
                    mn = a[v[i]];
                    mn_loc = v[i];
                }
                else if (a[v[i]] > mx)
                {
                    increasing = true;
                    decreasing = false;
                    moves++;
                    mp[mn_loc] += moves;
                    mx = a[v[i]];
                    mx_loc = v[i];
                }
            }
        }

        // final answer is maximum of all nodes value.
        ll res = 0;
        for (auto x : mp)
        {
            res = max(res, x.ss);
        }
        cout << res << nl;
    }
    return 0;
}