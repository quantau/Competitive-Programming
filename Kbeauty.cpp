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

    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll val = stoi(s);
    ll n = s.size();
    ll res = 0;
    for (ll i = 0; i <= n - k; i++)
    {
        string str = s.substr(i, k);
        ll num = stoi(str);
        if (num == 0)
            continue;
        if (val % num == 0)
        {
            res++;
        }
    }
    cout << res << nl;
    return 0;
}