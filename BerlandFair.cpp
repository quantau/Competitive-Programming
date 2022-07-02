#include <bits/stdc++.h>
#define sz(x) x.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << " ";
#define ll long long int
#define pii pair<ll, ll>
#define pb push_back
#define ff first
#define ss second

using namespace std;

ll n, t, mn = INT_MAX, res = 0;
const ll MAXN = 2 * 1e5 + 1;
ll a[MAXN + 5];

void get(ll &cnt, ll &sum)
{
    cnt = 0;
    sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if (t >= a[i])
        {
            t -= a[i];
            sum += a[i];
            cnt++;
            res++;
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

    cin >> n >> t;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    while (t >= mn)
    {
        ll cnt, sum;
        get(cnt, sum);
        res += cnt * (t / sum);
        t = t % sum;
    }
    cout << res << nl;
    return 0;
}