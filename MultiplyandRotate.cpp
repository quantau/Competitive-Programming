#include <bits/stdc++.h>
#define sz(x) x.size()
#define aint(v) v.begin(), v.end()
#define raint(v) v.rbegin(), v.rend()
#define nl "\n";
#define dbg(i) cout << "HERE " << i << endl;
#define var(x, y, z) cout << x << " " << y << " " << z << endl;
#define ll long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second

using namespace std;

int op(int x)
{
    int num = x;
    int base = 1;
    while (num > 0)
    {
        num /= 10;
        base *= 10;
    }
    base /= 10;
    return (x % base) * (10) + (x / base);
}

bool check(int x)
{
    string str = to_string(x);
    ll n = str.size();
    if (n > 1 && str[1] != '0')
        return true;
    return false;
}

int inf = 1e9 + 7;
// bool vis[10000001];
vector<int> d(10000001, inf);

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    // cout << op(70700);
    int a, n;
    cin >> a >> n;
    queue<pii> q;
    q.push({n, 0});
    d[n] = 0;
    while (!q.empty())
    {
        int val = q.front().ff;
        int dis = q.front().ss;
        q.pop();
        // var(val, dis, -1);
        // vis[val] = true;
        if (val % a == 0)
        {
            if (d[val / a] > dis + 1)
            {
                d[val / a] = dis + 1;
                q.push({val / a, dis + 1});
            }
        }
        if (check(val))
        {
            int v = op(val);
            if (d[v] > dis + 1)
            {
                d[v] = dis + 1;
                q.push({v, dis + 1});
            }
        }
    }
    cout << (d[1] == inf ? -1 : d[1]) << nl;
    return 0;
}