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

    ll n, m;
    cin >> n >> m;
    ll a[m];
    vector<ll> d(n + 1, 0);
    vector<ll> s;
    string str = "";
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
        d[a[i]]++;
        if (d[a[i]] == 1)
        {
            s.pb(a[i]);
        }
        if (s.size() == n)
        {
            str += '1';
            vector<ll> st;
            for (auto x : s)
            {
                d[x]--;
                if (d[x])
                {
                    st.pb(x);
                }
            }
            s = st;
        }
        else
        {
            str += '0';
        }
    }
    cout << str << nl;
    return 0;
}