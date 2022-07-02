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

ll freq[200001];
ll n, k;

void solve(ll a[])
{
    for (ll i = 0; i < n; i++)
    {
        if (!a[i] && k)
        {
            a[i] = 1;
            k--;
            freq[i]++;
        }
    }
    if (k % 2)
    {
        a[n - 1] = 0;
        k--;
        freq[n - 1]++;
    }
    freq[0] += k;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        string s;
        cin >> s;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            freq[i] = 0;
            a[i] = s[i] - '0';
        }
        if (k % 2)
        {
            bool b = false;
            for (ll i = 0; i < n; i++)
            {
                if (a[i] && !b)
                {
                    b = true;
                    freq[i]++;
                }
                else
                {
                    a[i] = !a[i];
                }
            }
            if (!b)
            {
                freq[n - 1]++;
                a[n - 1] = 0;
            }
            k--;
        }
        solve(a);
        for (ll i = 0; i < n; i++)
        {
            cout << a[i];
        }
        cout << nl;
        for (ll i = 0; i < n; i++)
        {
            cout << freq[i] << " ";
        }
        cout << nl;
    }
    return 0;
}
