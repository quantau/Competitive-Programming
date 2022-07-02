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

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<ll> stk;
    for (ll i = 0; i < n; i++)
    {
        while (!stk.empty() && a[stk.top()] >= a[i])
        {
            stk.pop();
        }
        if (stk.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << stk.top() + 1 << " ";
        }
        stk.push(i);
    }
    return 0;
}