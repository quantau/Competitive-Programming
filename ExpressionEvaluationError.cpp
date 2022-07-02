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

void solve(vector<ll> &v, ll &sum, ll &n, ll i)
{
    if (i == 0)
        return;
    if (i >= v.size())
        return;
    while (sum < n)
    {
        if (v[i])
        {
            v[i]--;
            v[i - 1] += 10;
            sum += 9;
            solve(v, sum, n, i - 1);
        }
        else
        {
            solve(v, sum, n, i + 1);
        }
    }
}

ll find_pow(ll x, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return find_pow(x * x, n / 2);
    }
    else
    {
        return x * find_pow(x * x, (n - 1) / 2);
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

    ll t;
    cin >> t;
    while (t--)
    {
        ll s, n;
        cin >> s >> n;
        vector<ll> v;
        ll num = s;
        ll sum = 0;
        while (num)
        {
            sum += num % 10;
            v.pb(num % 10);
            num /= 10;
        }
        // for (ll i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << nl;
        if (sum < n)
        {
            solve(v, sum, n, 1);
        }
        while (n > 1)
        {
            for (ll i = v.size() - 1; i >= 0; i--)
            {
                while (v[i])
                {
                    cout << find_pow(10, i) << " ";
                    n--;
                    v[i]--;
                    if (n == 1)
                        break;
                }
                if (n == 1)
                    break;
            }
        }
        ll res = 0;
        for (ll i = 0; i < v.size(); i++)
        {
            res += v[i] * find_pow(10, i);
        }
        cout << res << nl;
    }
    return 0;
}