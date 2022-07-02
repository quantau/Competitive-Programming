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

class Solution
{
public:
    int p[100005];
    int len[100005];

    int get_dsu(int x)
    {
        if (p[x] == x)
            return x;
        p[x] = get_dsu(x);
        return p[x];
    }

    void union_dsu(int x, int y)
    {
        x = get_dsu(x);
        y = get_dsu(y);
        if (x == y)
            return;
        if (len[x] < len[y])
            swap(x, y);
        len[x] += len[y];
        p[y] = x;
    }

    string kPeriodic(string s, int K)
    {
        // code here
        int n = s.size();
        map<char,int> mp;
        set<ll> st;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(auto x:st)
        {
                
        }

        for (int i = 0; i < n; i++)
        {
            p[i] = i;
            len[i] = 1;
        }

        //checking for right push
        for (int i = 0; i < n; i++)
        {
            union_dsu(i, (n + i - K) % n);
        }

        
    }
};

int main()
{
    FASTIO

    return 0;
}