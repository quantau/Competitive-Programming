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

bool check(multiset<ll> s, multiset<ll> st)
{
    while (!s.empty())
    {
        if (*s.begin() != *st.begin())
            return false;
        s.erase(s.begin());
        st.erase(st.begin());
    }
    return true;
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
        ll n, sum = 0;
        cin >> n;
        ll m = 1 << n;
        multiset<ll> s;
        for (ll i = 0; i < m; i++)
        {
            ll x;
            cin >> x;
            sum += x;
            s.insert(x);
        }
        multiset<ll> st;
        st.insert(sum);
        for (ll i = 0; i < n; i++)
        {
            multiset<ll> s2;
            while (!st.empty())
            {
                ll val = *st.begin();
                st.erase(st.begin());
                if (val % 2)
                {
                    s2.insert(val / 2);
                    s2.insert(val / 2 + 1);
                }
                else
                {
                    s2.insert(val / 2);
                    s2.insert(val / 2);
                }
            }
            st = s2;
        }
        if (check(s, st))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}