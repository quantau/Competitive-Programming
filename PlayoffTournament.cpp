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
ll tree[1000001];
ll a[1000001];

void build(ll node, ll len)
{
    if (node > len / 2)
    {
        if (a[node] == 1 || a[node] == 0)
        {
            tree[node] = 1;
        }
        else
        {
            tree[node] = 2;
        }
    }
    else
    {
        build(2 * node, len);
        build(2 * node + 1, len);
        if (a[node] == 1)
        {
            tree[node] = tree[2 * node + 1];
        }
        else if (a[node] == 0)
        {
            tree[node] = tree[2 * node];
        }
        else
        {
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
}

void update(ll node, ll len)
{
    if (node == 0)
    {
        return;
    }
    else if (node <= len / 2)
    {
        if (a[node] == 1)
        {
            tree[node] = tree[2 * node + 1];
        }
        else if (a[node] == 0)
        {
            tree[node] = tree[2 * node];
        }
        else
        {
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
        update(node / 2, len);
    }
    else
    {
        if (a[node] == 1 || a[node] == 0)
        {
            tree[node] = 1;
        }
        else
        {
            tree[node] = 2;
        }
        update(node / 2, len);
    }
}

int main()
{
    //optimization tool
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll k, k2;
    cin >> k;
    k2 = k;
    string s;
    cin >> s;
    ll len = 1;
    while (k2--)
        len *= 2;
    // len /= 2;
    len--;
    //1--> greater index win 0--> lower index wins -1--> either can win
    ll num = len;
    ll rep[len];
    while (k--)
    {
        //ll j = 1;
        ll val = len - num / 2 - 1;
        for (ll i = num; i > num / 2; i--)
        {
            rep[val+1] = i;
             //var(i, 0, val);
            if (s[val] == '?')
            {
                a[i] = -1;
            }
            else
            {
                a[i] = s[val] - '0';
            }
            val--;
        }
        num /= 2;
    }
    build(1, len);
    // for (ll i = 1; i <= len; i++)
    //     cout << tree[i] << " ";
    // cout << nl;
    // for (ll i = 1; i <= len; i++)
    //     cout << rep[i] << " ";
    // cout << nl;
    ll q;
    cin >> q;
    while (q--)
    {
        ll pos, upd;
        char c;
        cin >> pos >> c;
        if (c == '?')
            upd = -1;
        else
        {
            upd = c - '0';
        }
        pos = rep[pos];
        a[pos] = upd;
        update(pos, len);
        // for (ll i = 1; i <= len; i++)
        //     cout << tree[i] << " ";
        // cout << nl;
        cout << tree[1] << nl;
    }
    return 0;
}