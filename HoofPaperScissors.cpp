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

ll char_to_int(char c)
{
    if (c == 'P')
    {
        return 0;
    }
    else if (c == 'H')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ll n;
    cin >> n;
    ll fr[3][n], bk[3][n];
    char c[n];
    cin >> c[0];
    fr[0][0] = 0;
    fr[1][0] = 0;
    fr[2][0] = 0;
    fr[char_to_int(c[0])][0] = 1;
    for (ll i = 1; i < n; i++)
    {
        cin >> c[i];
        fr[0][i] = 0;
        fr[1][i] = 0;
        fr[2][i] = 0;
        fr[char_to_int(c[i])][i] = 1;
        fr[0][i] += fr[0][i - 1];
        fr[1][i] += fr[1][i - 1];
        fr[2][i] += fr[2][i - 1];
    }
    bk[0][n - 1] = 0;
    bk[1][n - 1] = 0;
    bk[2][n - 1] = 0;
    bk[char_to_int(c[n - 1])][n - 1] = 1;
    for (ll i = n - 2; i >= 0; i--)
    {
        bk[0][i] = 0;
        bk[1][i] = 0;
        bk[2][i] = 0;
        bk[char_to_int(c[i])][i] = 1;
        bk[0][i] += bk[0][i + 1];
        bk[1][i] += bk[1][i + 1];
        bk[2][i] += bk[2][i + 1];
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < 3; j++)
    //     {
    //         cout << fr[j][i] << " ";
    //     }
    //     cout << nl;
    // }
    ll res = max({fr[0][n - 1], fr[1][n - 1], fr[2][n - 1]});
    for (ll i = 0; i < n - 1; i++)
    {
        for (ll j = 0; j < 3; j++)
        {
            for (ll k = 0; k < 3; k++)
            {
                res = max(res, fr[j][i] + bk[k][i + 1]);
            }
        }
    }
    cout << res << nl;
    return 0;
}