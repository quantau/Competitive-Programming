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

using namespace std;

bool a[101][101];

bool is_Safe(ll i, ll j, ll n)
{
    for (ll k = 1; k <= n; k++)
    {
        //var(k, 0, 0);
        if (i + k < n && a[i + k][j])
            return false;
        if (i - k >= 0 && a[i - k][j])
            return false;
        if (j + k < n && a[i][j + k])
            return false;
        if (j - k >= 0 && a[i][j - k])
            return false;
        if (i - k >= 0 && j + k < n && a[i - k][j + k])
            return false;
        if (i + k < n && j - k >= 0 && a[i + k][j - k])
            return false;
        if (i - k >= 0 && j - k >= 0 && a[i - k][j - k])
            return false;
        if (i + k < n && j + k < n && a[i + k][j + k])
            return false;
    }
    return true;
}

bool check(ll n)
{
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            // cout << i << " " << j << " " << is_Safe(i, j, n) << nl;
            if (is_Safe(i, j, n))
            {
                var(i, j, n);
                return false;
            }
        }
    }
    return true;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("QueensPlacementout.txt", "w", stdout);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        //dbg(n);
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                a[i][j] = 0;
            }
        }
        if (n == 3)
        {
            a[1][1] = 1;
        }
        else if (n % 2 == 0)
        {
            a[0][0] = 1;
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < n; j++)
                {
                    if (i == j && i > 1 && i < n - 1)
                    {
                        a[i][j] = 1;
                    }
                }
            }
        }
        else
        {
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < n; j++)
                {
                    if (i == j && i > 0 && i < n - 1)
                    {
                        a[i][j] = 1;
                    }
                }
            }
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cout << (a[i][j] == 1 ? "Q" : ".");
            }
            cout << nl;
        }
        // if (check(n))
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}