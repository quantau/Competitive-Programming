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
        // I/O
        ll n;
        cin >> n;
        n *= 2;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        // pre-processing
        sort(rall(v));
        map<ll, set<ll>> mp;
        for (ll i = 0; i < n; i++)
        {
            mp[v[i]].insert(i);
        }

        ll index = -1;
        vector<pii> vec;
        for (ll i = 1; i < n; i++)
        {
            vector<bool> vis(n, 0);
            vis[0] = 1, vis[i] = 1;
            auto mp2 = mp;
            mp2[v[0]].erase(0), mp2[v[i]].erase(i);
            ll val = v[0];
            bool chk = true;
            vec.pb({0, i});
            for (ll j = 0; j < n; j++)
            {
                if (vis[j])
                    continue;
                mp2[v[j]].erase(j);
                if (mp2[val - v[j]].empty())
                {
                    chk = false;
                    break;
                }
                auto it = mp2[val - v[j]].begin();
                mp2[val - v[j]].erase(it);
                val = v[j];
                vis[*it] = true;
                vis[j] = true;
                vec.pb({j, *it});
            }
            if (chk)
            {
                index = i;
                break;
            }
            vec.clear();
        }
        if (index == -1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << v[0] + v[index] << nl;
            for (auto x : vec)
            {
                cout << v[x.ff] << " " << v[x.ss] << nl;
            }
        }
    }
    return 0;
}