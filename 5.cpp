#include <iostream>
#include <vector>
#include <tuple>

#define INF_WEIGTH 100000000000
#define MIN_VERTEX -1

int main()
{
    // Dijkstra algo
    int N, M, A, B;
    int C;
    std::cin >> N >> M;

    // adjacency list
    std::vector<std::vector<std::tuple<int, long>>> graph;
    bool visited[N];
    long long distances[N];

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
        distances[i] = INF_WEIGTH;
        graph.push_back(std::vector<std::tuple<int, long>>());
    }


    for (int i = 0; i < M; i++)
    {
        std::cin >> A >> B >> C;

        graph[A - 1].push_back(std::make_tuple(B - 1, C));
        graph[B - 1].push_back(std::make_tuple(A - 1, C));
    }

    int start, end;
    std::cin >> start >> end;
    start--; end--;
    distances[start] = 0;

    for (int i = 0; i < N; i++)
    {
        // find "cheapest" not visited vertex
        int min_vertex = MIN_VERTEX;

        for (int k = 0; k < N; k++)
        {
            if (!visited[k] && (min_vertex == MIN_VERTEX || distances[k] < distances[min_vertex]))
                min_vertex = k;
        }

        // update distances
        for (int k = 0; k < graph[min_vertex].size(); k++)
        {
            int vertex = std::get<0>(graph[min_vertex][k]);
            int weight = std::get<1>(graph[min_vertex][k]);

            if (distances[min_vertex] + weight < distances[vertex])
                distances[vertex] = distances[min_vertex] + weight;
        }

        visited[min_vertex] = true;
    }

    std::cout << distances[end];

    return 0;
}
