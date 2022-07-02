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

ll n;

void solve(ll a[], ll b[])
{
    stack<ll> stk;
    for (ll i = 0; i < n; i++)
    {
        while (!stk.empty() && a[stk.top()] >= a[i])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            b[i] = -1;
        }
        else
        {
            b[i] = stk.top();
        }
        stk.push(i);
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

    cin >> n;
    ll a[n], b[n], c[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, b);
    for (ll i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - i - 1]);
    }
    solve(a, c);
    for (ll i = 0; i < n / 2; i++)
    {
        swap(a[i], a[n - i - 1]);
    }
    for (ll i = 0; i < n; i++)
    {
        c[i] = n - c[i] - 1;
    }
    vector<ll> r(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        r[c[n - i - 1] - b[i] - 1] = max(a[i], r[c[n - i - 1] - b[i] - 1]);
    }
    for (ll i = n - 1; i >= 1; i--)
    {
        r[i] = max(r[i], r[i + 1]);
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << r[i] << " ";
    }
    cout << nl;
    return 0;
}