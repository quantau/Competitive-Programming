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
#define ss sec

using namespace std;

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n, cont = 0;
    cin >> n;
    string s;
    cin >> s;
    int b1 = 0, r1 = 0, b2 = 0, r2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && s[i] == 'b')
        {
            b1++;
        }
        else if (i % 2 == 1 && s[i] == 'r')
        {
            r1++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1 && s[i] == 'b')
        {
            b2++;
        }
        else if (i % 2 == 0 && s[i] == 'r')
        {
            r2++;
        }
    }
    int first = max(b1, r1);
    int sec = max(b2, r2);
    if (first > sec)
    {
        cout << sec;
    }
    else
    {
        cout << first;
    }
    return 0;
}