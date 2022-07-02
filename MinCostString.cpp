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
    ll n, k;
    cin >> n >> k;
    map<char, queue<char>> mp;
    for (ll i = 0; i < k; i++)
    {
        for (ll j = i; j < k; j++)
        {
            mp['a' + i].push('a' + j);
        }
        for (ll j = 0; j < i; j++)
        {
            mp['a' + i].push('a' + j);
        }
    }
    string s = "a";
    for (ll i = 0; i < min(k * k, n); i++)
    {
        char c = mp[s[i]].front();
        mp[s[i]].pop();
        s += c;
    }
    s.pop_back();
    ll m = s.size();
    string str = "";
    for (ll i = 1; i * m <= n; i++)
    {
        str += s;
    }
    m = str.size();
    if (n - m == 0)
    {
        cout << str << nl;
        return 0;
    }
    str += s.substr(0, n - m);
    cout << str << nl;
    return 0;
}