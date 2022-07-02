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
#define on_bit(x) __builtin_popcountll(x)
#define msb(x) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
#define FREOPEN                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

using namespace std;

struct TrieNode
{
    struct TrieNode *children[2];
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->children[0] = NULL;
    pNode->children[1] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, ll x)
{
    struct TrieNode *Node = root;
    for (ll i = 16; i >= 0; i--)
    {
        bool b = (x & (1 << i));
        if (!Node->children[b])
        {
            Node->children[b] = getNode();
        }
        Node = Node->children[b];
    }
}

ll get_min(struct TrieNode *root, ll x)
{
    ll val = 0;
    struct TrieNode *Node = root;
    for (ll i = 16; i >= 0; i--)
    {
        bool b = (x & (1 << i));
        if (Node->children[b])
        {
            Node = Node->children[b];
        }
        else
        {
            Node = Node->children[!b];
            val += (1 << i);
        }
    }
    return val;
}

ll get_max(struct TrieNode *root, ll x)
{
    ll val = 0;
    struct TrieNode *Node = root;
    for (ll i = 16; i >= 0; i--)
    {
        bool b = (x & (1 << i));
        if (Node->children[!b])
        {
            Node = Node->children[!b];
            val += (1 << i);
        }
        else
        {
            Node = Node->children[b];
        }
    }
    return val;
}

void solve()
{
    struct TrieNode *root = getNode();
    ll l, r;
    cin >> l >> r;
    vector<ll> v;
    for (ll i = l; i <= r; i++)
    {
        ll a;
        cin >> a;
        v.pb(a);
        insert(root, a);
    }
    for (auto x : v)
    {
        ll val = (x ^ l);
        if (get_min(root, val) == l && get_max(root, val) == r)
        {
            cout << val << nl;
            return;
        }
    }
    // cout << "NOTHING\n";
}

int main()
{
    FASTIO

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
