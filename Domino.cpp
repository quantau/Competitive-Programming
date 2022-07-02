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

char a[101][101];

bool solve(ll k, ll n, ll m)
{
    if (k % 2 || ((n * m) / 2 - k) < n / 2 || ((n * m) / 2 - k - n / 2) % 2)
    {
        cout << "NO\n";
        return false;
    }
    else
    {
        cout << "YES\n";
        return true;
    }
}

void gen(ll n, ll m, ll k, char c, ll ii, ll jj)
{
    ll i, j;
    for (j = jj; j < m; j += 2)
    {
        for (i = ii; (i < n && k > 0); i++, k--)
        {
            a[i][j] = c;
            a[i][j - 1] = c;
            c++;
            if (c > 122)
            {
                c = 'a';
            }
        }
        for (ll l = i; l < n; l += 2)
        {
            // var(i, j, l);
            a[l][j - 1] = c;
            a[l + 1][j - 1] = c;
            c++;
            a[l][j] = c;
            a[l + 1][j] = c;
            c++;
            if (c > 122)
            {
                c = 'a';
            }
        }
    }
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        if (n % 2 == 0 && m % 2 == 0)
        {
            if (k % 2)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
                gen(n, m, k, 'a', 0, 1);
                for (ll i = 0; i < n; i++)
                {
                    for (ll j = 0; j < m; j++)
                    {
                        cout << a[i][j];
                    }
                    cout << nl;
                }
            }
        }
        else if (m % 2)
        {
            if (solve(k, n, m))
            {
                char c = 'a';
                for (ll i = 1; i < n; i += 2)
                {
                    a[i][0] = c;
                    a[i - 1][0] = c;
                    c++;
                    if (c > 122)
                    {
                        c = 'a';
                    }
                }
                gen(n, m, k, c, 0, 2);
                for (ll i = 0; i < n; i++)
                {
                    for (ll j = 0; j < m; j++)
                    {
                        cout << a[i][j];
                    }
                    cout << nl;
                }
            }
        }
        else
        {
            k = (n * m) / 2 - k;
            if (solve(k, m, n))
            {
                char c = 'a';
                for (ll i = 1; i < m; i += 2)
                {
                    a[i][0] = c;
                    a[i - 1][0] = c;
                    c++;
                    if (c > 122)
                    {
                        c = 'a';
                    }
                }
                gen(m, n, k, c, 0, 2);
                for (ll i = n - 1; i >= 0; i--)
                {
                    for (ll j = 0; j < m; j++)
                    {
                        cout << a[j][i];
                    }
                    cout << nl;
                }
            }
        }
    }
    return 0;
}