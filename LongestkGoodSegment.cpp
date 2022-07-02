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

const int MAXN = 1e6 + 5;
ll freq[MAXN];

int main()
{
    FASTIO

    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<ll> s;
    ll l = -1, r = -1, j = 0;
    for (ll i = 0; i < n; i++)
    {
        s.insert(a[i]);
        freq[a[i]]++;
        while (s.size() > k)
        {
            freq[a[j]]--;
            if (!freq[a[j]])
                s.erase(a[j]);
            j++;
        }
        if (r - l + 1 <= i - j + 1)
        {
            l = j, r = i;
        }
    }
    cout << l + 1 << " " << r + 1 << nl;
    return 0;
}