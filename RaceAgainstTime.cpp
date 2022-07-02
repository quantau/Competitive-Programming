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

bool check(double t1, double t2, double l, double r)
{
    if (t1 == t2)
        return true;
    if (t1 >= l && t1 <= r && t2 >= l && t2 <= r)
        return true;
    return false;
}
bool check2(double t, double l, double r)
{
    if (t >= l && t <= r)
        return true;
    return false;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    double t[3], t1, t2;
    cin >> t[0] >> t[1] >> t[2] >> t1 >> t2;
    t[0] *= 5;
    t[1] += t[2] / 60;
    t[0] += t[1] / 60;
   //var(t[0], t[1], t[2]);
    t1 *= 5;
    t2 *= 5;
    sort(t, t + 3);
    if (t1 == t2)
    {
        cout << "YES\n";
        return 0;
    }
    if (t2 == t[0] || t2 == t[1] || t2 == t[2])
    {
        cout << "NO\n";
        return 0;
    }
    if (check(t1, t2, t[0], t[1]))
    {
        cout << "YES\n";
    }
    else if (check(t1, t2, t[1], t[2]))
    {
        cout << "YES\n";
    }
    else if ((check2(t1, t[2], 60) || check2(t1, 0, t[0])) && (check2(t2, t[2], 60) || check2(t2, 0, t[0])))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}