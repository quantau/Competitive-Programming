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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        multiset<ll> s;
        cin >> n;
        while (n)
        {
            s.insert(n % 10);
            n /= 10;
        }
        ll n1 = 0, n2 = 0;
        while (!s.empty())
        {
            auto it = s.begin();
            n1 = n1 * 10 + *it;
            s.erase(it);
            if (s.empty())
                break;
            it = s.begin();
            n2 = n2 * 10 + *it;
            s.erase(it);
        }
        //var(n1, n2, 0);
        cout << n1 + n2 << nl;
    }
    return 0;
}