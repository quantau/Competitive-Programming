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

class TrieNode
{
public:
    TrieNode *next[2];
    TrieNode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode;
    }
    void insert(int num)
    {
        TrieNode *node = root;
        for (int i = 30; i >= 0; i--)
        {
            bool b = (num & (1 << i));
            if (!node->next[b])
            {
                node->next[b] = new TrieNode;
            }
            node = node->next[b];
        }
    }

    int get_max(int num, int val, int state)
    {
        TrieNode *node = root;
        int res = 0;
        for (int i = 30; i >= 0; i--)
        {
            bool b = num & (1 << i);
            cout << b << " " << (val & (1 << i)) << " " << state << endl;
            if (state || val & (1 << i))
            {
                if (node->next[!b])
                {
                    res += (1 << i);
                    node = node->next[!b];
                    if (b == 1)
                    {
                        state = 1;
                    }
                }
                else
                {
                    node = node->next[b];
                    if (b == 0)
                    {
                        state = 1;
                    }
                }
            }
            else
            {
                if (node->next[0])
                {
                    res += b * (1 << i);
                    node = node->next[0];
                }
                else
                {
                    break;
                }
            }
        }
        return res;
    }

private:
    TrieNode *root;
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        Trie my_trie;
        int min_Val = 1e9;
        for (int i = 0; i < nums.size(); i++)
        {
            min_Val = min(min_Val, nums[i]);
            my_trie.insert(nums[i]);
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
        {
            int num = queries[i][0];
            int val = queries[i][1];
            if (val < min_Val)
            {
                res.push_back(-1);
                continue;
            }
            int ans = my_trie.get_max(num, val, 0);
            res.push_back(ans);
        }
        return res;
    }
};

int main()
{
    FASTIO
    vector<int> nums = {536870912, 0, 534710168, 330218644, 142254206};
    vector<vector<int>> queries;
    vector<int> v = {214004, 404207941};
    queries.pb(v);
    vector<int> vec = {536870912, 0, 534710168, 330218644, 142254206, 214004, 404207941,402653184};
    for (auto x : vec)
    {
        for (int i = 30; i >= 0; i--)
        {
            bool b = (x & (1 << i));
            cout << b << " ";
        }
        cout << nl;
    }
    Solution Sol;
    cout << Sol.maximizeXor(nums, queries)[0] << nl;
    return 0;
}