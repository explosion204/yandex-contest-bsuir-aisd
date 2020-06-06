#include <iostream>
#include <vector>

const long MOD = 10000007;

int dfs(std::vector<std::vector<std::pair<int, int>>>& graph, int root, int node, long long& sum)
{
    int tree_size = 1;

    for (int i = 0; i < graph[node].size(); i++)
    {
        int child = graph[node][i].first;
        int child_weight = graph[node][i].second;
        if (child != root)
        {
            long subtree_size = dfs(graph, node, child, sum);
            tree_size += subtree_size;
            sum += (2 * subtree_size * child_weight * (graph.size() - subtree_size));
            sum %= MOD;
        }
    }

    return tree_size;
}

int main()
{
    int N, A, B, C;
    std::cin >> N;

    // adjacency list graph representation
    std::vector<std::vector<std::pair<int, int>>> graph(N, std::vector<std::pair<int, int>>());

    for (int i = 0; i < N - 1; i++)
    {
        std::cin >> A >> B >> C;
        graph[A - 1].push_back(std::make_pair(B - 1, C));
        graph[B - 1].push_back(std::make_pair(A - 1, C));
    }

    long long sum = 0;
    for (int i = 0; i < graph[0].size(); i++)
    {
        int child = graph[0][i].first;
        int child_weight = graph[0][i].second;
        long subtree_size = dfs(graph, 0, child, sum);
        sum += (2 * subtree_size * child_weight * (graph.size() - subtree_size));
        sum %= MOD;
    }

    std::cout << sum;

    return 0;
}
