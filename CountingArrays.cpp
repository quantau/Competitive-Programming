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
    set<vector<ll>> s;
    for (ll i = 0; i < n; i++)
    {
        ll k; S
        cin >> k;
        vector<ll> v(k);
        for (ll j = 0; j < k; j++)
        {
            cin >> v[j];
        }
        s.insert(v);
    }
    cout << s.size() << nl;
    return 0;
}