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
        map<char, ll> mp;
        ll n;
        cin >> n;
        string t[2 * n];
        string str;
        for (ll i = 0; i < 2 * n; i++)
        {
            cin >> t[i];
            for (auto x : t[i])
            {
                mp[x]++;
            }
        }
        cin >> str;
        map<ll, ll> mp2;
        for (auto x : str)
        {
            mp2[x]++;
        }
        for (auto x : mp)
        {
            if ((x.ss - mp2[x.ff]) % 2)
            {
                cout << x.ff << nl;
            }
        }
    }
    return 0;
}