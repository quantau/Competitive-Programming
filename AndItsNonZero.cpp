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

const ll N = 2 * 1e5 + 1;
const ll M = 20;
ll arr[M][N];

void pre()
{
    for (ll i = 0; i < M; i++)
    {
        for (ll j = 1; j < N; j++)
        {
            arr[i][j] = arr[i - 1][j] + ((j >> i) & 1);
        }
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    pre();
    ll t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        for (ll i = 0; i < M; i++)
        {
            ans = max(ans, arr[r] - arr[l - 1]);
        }
        cout << (r - l + 1) - ans << nl;
    }
    return 0;
}