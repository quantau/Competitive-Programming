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

ll n, k;

string solve(string s)
{
    string str = "";
    while (str.size() < k)
    {
        str += s;
    }
    if (str.size() > k)
    {
        str.erase(k);
    }
    return str;
}

int main()
{
    FASTIO

    cin >> n >> k;
    string s;
    cin >> s;
    ll j = 0, l = n - 1;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] > s[j])
        {
            l = min(l, i - 1);
            break;
        }
        else if (s[i] < s[j])
        {
            l = n - 1;
            j = 0;
        }
        else
        {
            j++;
            l = min(l, i - 1);
        }
    }
    s.erase(l + 1);
    s = solve(s);
    cout << s << nl;
    return 0;
}