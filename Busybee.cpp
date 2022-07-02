#include <bits/stdc++.h>

using namespace std;

// edges[i] is a vector of size 2 - (u, v).
vector<int> adj[1005];
map<int, int> mp;
int len[1005];

void dfs(int node, int p)
{
    for (auto x : adj[node])
    {
        if (x == p)
            continue;
        dfs(x, node);
        len[node] += len[x];
    }
}

vector<int> minimumEdges(int n, vector<vector<int>> &edges)
{
    mp.clear();
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i][1];
        int v = edges[i][0];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            len[j] = 1;
        }
        dfs(i, -1);
        for (int j = 1; j <= n; j++)
        {
            mp[len[j]]++;
        }
    }
    vector<int> res;
    for (int i = 1; i < n; i++)
    {
        if (mp[i] || mp[n - i])
        {
            res.push_back(1);
        }
        else
        {
            res.push_back(2);
        }
    }
    res.push_back(0);
    return res;
}

int main()
{
    
}