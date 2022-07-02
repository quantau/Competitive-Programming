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
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO\n";
        return 0;
    }
    set<ll> s[2];
    for (ll i = 1; i <= (n + 1) / 2; i++)
    {
        s[i % 2].insert(i);
        s[i % 2].insert(n + 1 - i);
    }
    if (n % 4)
    {
        s[0]
    }
    return 0;
}