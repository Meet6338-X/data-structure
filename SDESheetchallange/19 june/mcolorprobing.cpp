#include <bits/stdc++.h>
using namespace std;

bool issafe(int node, vector<vector<int>> &graph, vector<int> &color, int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (graph[node][k] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}

bool solve(int node, vector<vector<int>> &graph, vector<int> &color, int m, int n)
{
    if (node == n)
    {
        return true;
    }
    for (int col = 1; col <= m; col++)
    {
        if (issafe(node, graph, color, n, col))
        {
            color[node] = col;
            if (solve(node + 1, graph, color, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>> &graph, int m, int n)
{
    vector<int> color(n, 0);
    return solve(0, graph, color, m, n);
}