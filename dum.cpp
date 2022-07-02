#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9 + 7
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    fast int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> s;
        int a[2 * n];
        rep(i, 2 * n) cin >> a[i], s.insert(a[i]);
        if (s.size() != n)
        {
            cout << "NO1" << endl;
            continue;
        }
        vector<int> v;
        for (int i : s)
            v.pb(i);
        int sum = 0;
        int f = 1;
        rrep(i, n)
        {
            cout << v[i] << " " << sum << " " << i << "\n";
            int num;
            v[i] -= sum;
            if (v[i] > 0 and v[i] % (2 * (i + 1)) == 0)
            {
                v[i] /= (2 * (i + 1));
                sum += 2 * v[i];
            }
            else
            {
                f = 0;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO2" << endl;
    }
    return 0;
}