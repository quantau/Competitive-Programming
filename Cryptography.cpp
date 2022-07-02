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

typedef struct
{
    ll a[2][2];
} matrix;

matrix arr[200002];
matrix tree[800008];
matrix identity;

ll r, n, m;

matrix add(matrix x, matrix y)
{
    matrix res;
    res.a[0][0] = ((x.a[0][0] * y.a[0][0]) % r + (x.a[0][1] * y.a[1][0] % r)) % r;
    res.a[0][1] = ((x.a[0][0] * y.a[0][1]) % r + (x.a[0][1] * y.a[1][1] % r)) % r;
    res.a[1][0] = ((x.a[1][0] * y.a[0][0]) % r + (x.a[1][1] * y.a[1][0] % r)) % r;
    res.a[1][1] = ((x.a[1][0] * y.a[0][1]) % r + (x.a[1][1] * y.a[1][1] % r)) % r;
    return res;
}

void build(ll node, ll strt, ll end)
{
    if (strt == end)
    {
        tree[node] = arr[strt];
    }
    else
    {
        ll mid = (strt + end) / 2;
        build(2 * node, strt, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = add(tree[2 * node], tree[2 * node + 1]);
    }
}

matrix query(ll node, ll strt, ll end, ll lo, ll hi)
{
    if (strt >= lo && end <= hi)
    {
        return tree[node];
    }
    else if (strt > hi || end < lo)
    {
        return identity;
    }
    else
    {
        ll mid = (strt + end) / 2;
        matrix q1 = query(2 * node, strt, mid, lo, hi);
        matrix q2 = query(2 * node + 1, mid + 1, end, lo, hi);
        return add(q1, q2);
    }
}

void print(matrix m)
{
    cout << m.a[0][0] << " " << m.a[0][1] << nl;
    cout << m.a[1][0] << " " << m.a[1][1] << nl;
    cout << nl;
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    identity.a[0][0] = 1;
    identity.a[0][1] = 0;
    identity.a[1][1] = 1;
    identity.a[1][0] = 0;
    cin >> r >> n >> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            for (ll k = 0; k < 2; k++)
            {
                cin >> arr[i].a[j][k];
            }
        }
    }
    build(1, 0, n - 1);
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        matrix res = query(1, 0, n - 1, l, r);
        print(res);
    }
    return 0;
}