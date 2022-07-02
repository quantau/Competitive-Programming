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

int inf = 1e8;
int dx[2] = {-1, 1};

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin >> n;
    vector<int> v[n];
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < 2; j++)
        {
            int node = i + a[i] * dx[j];
            if (node >= 0 && node < n)
            {
                v[node].pb(i);
            }
        }
    }
    int r[n];
    queue<int> q;
    int d[n]; //geeting shortest path for odds
    for (int i = 0; i < n; i++)
    {
        d[i] = inf;
        if (a[i] % 2 == 0)
        {
            d[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int scr = q.front();
        q.pop();
        for (auto x : v[scr])
        {
            if (d[x] <= d[scr] + 1)
                continue;
            d[x] = d[scr] + 1;
            q.push(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
        {
            r[i] = (d[i] == inf ? -1 : d[i]);
            d[i] = 0;
            q.push(i);
        }
        else
        {
            d[i] = inf;
        }
    }
    while (!q.empty())
    {
        int scr = q.front();
        q.pop();
        for (auto x : v[scr])
        {
            if (d[x] <= d[scr] + 1)
                continue;
            d[x] = d[scr] + 1;
            q.push(x);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            r[i] = (d[i] == inf ? -1 : d[i]);
        }
        cout << r[i] << " ";
    }
    return 0;
}