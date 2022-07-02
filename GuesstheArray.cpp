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
    ll a[n + 1];
    ll i;
    for (i = 3; i <= n; i += 3)
    {
        cout << "? " << i - 2 << " " << i - 1 << endl;
        ll sum1;
        cin >> sum1;
        cout << "? " << i - 1 << " " << i << endl;
        ll sum2;
        cin >> sum2;
        cout << "? " << i - 2 << " " << i << endl;
        ll sum3;
        cin >> sum3;
        ll sum = sum1 - sum2;
        a[i - 2] = (sum + sum3) / 2;
        a[i] = a[i - 2] - sum;
        a[i - 1] = sum1 - a[i - 2];
    }
    i -= 2;
    while (i <= n)
    {
        cout << "? " << 1 << " " << i << endl;
        ll sum;
        cin >> sum;
        a[i] = sum - a[1];
        i++;
    }
    cout << "! ";
    for (ll i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}