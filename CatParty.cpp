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
    vector<ll> c(11, 0);
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        c[a[i]]++;
        set<ll> s;
        for (ll j = 1; j <= 10; j++)
        {
            if (!c[j])
                continue;
            s.insert(c[j]);
        }
        // for (auto x : s)
        // {
        //     cout << x << " ";
        // }
        // cout << nl;
        if (s.size() == 2)
        {
            auto it1 = s.begin();
            auto it2 = s.end();
            it2--;
            if (abs(*it1 - *it2) == 1 || *it1 == 1)
            {
                ll count[2] = {0, 0};
                for (ll j = 1; j <= 10; j++)
                {
                    if (c[j] == *it1)
                    {
                        count[0]++;
                    }
                    else if (c[j] == *it2)
                    {
                        count[1]++;
                    }
                }
                if ((count[1] == 1 && abs(*it1 - *it2) == 1) || (count[0] == 1 && *it1 == 1))
                {
                    ans = max(ans, i + 1);
                }
            }
        }
        else if (s.size() == 1)
        {
            ll count = 0;
            for (ll j = 1; j <= 10; j++)
            {
                if (c[j] == (*s.begin()))
                {
                    count++;
                }
            }
            if (count == 1 || ((*s.begin() == 1)))
            {
                ans = max(ans, i + 1);
            }
        }
        // cout << ans << " ";
    }
    cout << ans << nl;
    return 0;
}
