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
        string s;
        cin >> s;
        sort(all(s));
        vector<pair<ll, char>> v;
        char c = s[0];
        ll cont = 1;
        for (ll i = 1; i < n; i++)
        {
            if (s[i] == c)
                cont++;
            else
            {
                v.pb({cont, s[i - 1]});
                cont = 1;
                c = s[i];
            }
        }
        v.pb({cont, s[n - 1]});
        sort(rall(v));
        if (v[0].ff > (n + 2) / 3)
        {
            cout << "NO\n";
            continue;
        }
        else if (n > 1 && v[1].ff > (n + 1) / 3)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        string vec;
        for (auto x : v)
        {
            ll num = x.ff;
            while (num--)
            {
                vec.pb(x.ss);
            }
        }
        bool vis[3] = {0};
        vector<char> res(n);
        if (v.size() > 2 && v[2].ff == n / 3)
        {
            vis[2] = 1;
            ll index = v[0].ff + v[1].ff;
            for (ll i = 2; i < 2 + 3 * (v[2].ff); i += 3)
            {
                res[i] = vec[index];
                index++;
            }
            vec = vec.substr(0, v[0].ff + v[1].ff) + vec.substr(v[0].ff + v[1].ff + v[2].ff, n - (v[0].ff + v[1].ff + v[2].ff));
        }
        if (v.size() > 1 && v[1].ff == (n + 1) / 3)
        {
            vis[1] = 1;
            ll index = v[0].ff;
            for (ll i = 1; i < 1 + 3 * (v[1].ff); i += 3)
            {
                res[i] = vec[index];
                index++;
            }
            vec = vec.substr(0, v[0].ff) + vec.substr(v[0].ff + v[1].ff, n - (v[0].ff + v[1].ff));
        }
        if (v.size() > 2 && v[2].ff == (n + 2) / 3)
        {
            vis[0] = 1;
            ll index = 0;
            for (ll i = 0; i < 3 * (v[0].ff); i += 3)
            {
                res[i] = vec[index];
                index++;
            }
            vec = vec.substr(v[0].ff, n - v[0].ff);
        }
        ll index = 0;
        for (ll i = 0; i < 3; i++)
        {
            if (vis[i])
                continue;
            for (ll j = i; j < n; j += 3)
            {
                res[j] = vec[index];
                index++;
            }
        }
        for (auto x : res)
        {
            cout << x;
        }
        cout << nl;
    }

    return 0;
}