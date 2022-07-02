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

ll findMaxGCD(ll arr[], ll n, ll k)
{
    // Computing highest element
    ll high = *max_element(arr, arr + n);

    // Array to store the count of divisors
    // i.e. Potential GCDs
    ll divisors[high + 1] = {0};

    // Iterating over every element
    for (ll i = 0; i < n; i++)
    {

        // Calculating all the divisors
        for (ll j = 1; j <= sqrt(arr[i]); j++)
        {

            // Divisor found
            if (arr[i] % j == 0)
            {

                // Incrementing count for divisor
                divisors[j]++;

                // Element/divisor is also a divisor
                // Checking if both divisors are
                // not same
                if (j != arr[i] / j)
                    divisors[arr[i] / j]++;
            }
        }
    }

    // Checking the highest potential GCD
    for (ll i = high; i >= 1; i--)

        // If this divisor can divide at least k
        // numbers, it is a GCD of at least one
        // sub sequence of size k
        if (divisors[i] >= k)
            return i;
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        while (q--)
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            ll b[r - l + 1];
            for (ll i = l; i <= r; i++)
            {
                b[i - l] = a[i];
            }
            ll res = findMaxGCD(b, r - l + 1, 2);
            cout << res << nl;
        }
    }
    return 0;
}