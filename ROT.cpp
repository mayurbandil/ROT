#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (auto i : edges)
        {
            int from = i[0];
            int to = i[1];
            int cost = i[2];

            pair<int, int> p1{to, cost};
            adj[from].push_back(p1);
        }
    }

    void addEdge(vector<int> edge)
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(adj.size(), INT_MAX);
        ans[node1] = 0;
        pq.push({0, node1});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto i : adj[node])
            {
                int v = i.first;
                int w = i.second;
                if (dis + w < ans[v])
                {
                    ans[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }

        if (ans[node2] == INT_MAX)
        {
            return -1;
        }

        return ans[node2];
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
