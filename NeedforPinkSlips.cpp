#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z, w) cout << x << " " << y << " " << z << " " << w << endl;
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

const double ep = 1e-6;
double b = 1;

double solve(double c, double m, double p, double v, double e)
{
    // if()
    double val = 0;
    // var(c, m, p, e);
    if (m - ep > 0 && c - ep > 0)
    {
        if (m - v > ep)
        {
            val += m * solve(c + v / 2, m - v, p + v / 2, v, e + 1);
        }
        else
        {
            val += m * solve(c + m / 2, 0, p + m / 2, v, e + 1);
        }
        if (c - v > ep)
        {
            val += c * solve(c - v, m + v / 2, p + v / 2, v, e + 1);
        }
        else
        {
            val += c * solve(0, m + c / 2, p + c / 2, v, e + 1);
        }
    }
    else if (m - ep > 0)
    {
        if (m - v > ep)
        {
            val += m * solve(c, m - v, p + v, v, e + 1);
        }
        else
        {
            val += m * solve(c, 0, p + m, v, e + 1);
        }
    }
    else if (c - ep > 0)
    {
        if (c - v > ep)
        {
            val += c * solve(c - v, m, p + v, v, e + 1);
        }
        else
        {
            val += c * solve(0, m, p + c, v, e + 1);
        }
    }
    val += p * e;
    return val;
}

int main()
{
    FASTIO
    // FREOPEN
    ll t;
    cin >> t;
    while (t--)
    {
        double c, m, p, v;
        cin >> c >> m >> p >> v;
        cout << setprecision(9) << solve(c, m, p, v, 1) << nl;
    }
    return 0;
}