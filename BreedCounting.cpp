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

ll pre[4][100001];

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);

    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pre[a[0]][0] += 1;
    for (ll i = 1; i < n; i++)
    {
        pre[a[i]][i]++;
        for (ll j = 1; j <= 3; j++)
        {
            pre[j][i] += pre[j][i - 1];
        }
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << pre[1][r] - pre[1][l] + (a[l] == 1) << " " << pre[2][r] - pre[2][l] + (a[l] == 2) << " " << pre[3][r] - pre[3][l] + (a[l] == 3) << nl;
    }
    return 0;
}