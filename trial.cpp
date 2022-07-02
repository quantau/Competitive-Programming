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

bool check(string str)
{
    ll m = str.size();
    vector<ll> freq(26, 0);
    for (ll i = 0; i < m; i++)
    {
        if (!freq[str[i] - 'A'] || (str[i] == str[i - 1]))
        {
            freq[str[i] - 'A']++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FASTIO
    cout << check("ZZZZZJAMMICCODEEEL");
    return 0;
}