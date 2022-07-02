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

vector<pii> edges;

void solve(ll x, vector<ll> v)
{
    if (v.empty())
    {
        return;
    }
    ll y = v[0];
    for (ll i = 1; i < v.size(); i++)
    {
        cout << "? 3" << x << " " << v[i] << " " << y << endl;
        ll chk;
        cin >> chk;
        if (chk)
        {
            y = v[i];
        }
    }
    edges.pb({x, y});
    vector<ll> vec[2];
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i] == y)
            continue;
        cout << "? 3" << v[i] << " " << x << " " << y << endl;
        ll chk;
        cin >> chk;
        if (chk)
        {
            vec[0].pb(v[i]);
        }
        else
        {
            vec[1].pb(v[i]);
        }
    }
    solve(x, vec[0]);
    solve(y, vec[1]);
}

int main()
{
    // FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        edges.clear();
        ll n;
        cin >> n;
        vector<ll> v;
        for (ll i = 2; i <= n; i++)
        {
            v.pb(i);
        }
        solve(1, v);
        cout << "!" << endl;
        for (auto x : edges)
        {
            cout << x.ff << " " << x.ss << endl;
        }
    }
    return 0;
}