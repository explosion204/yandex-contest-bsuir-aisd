using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);

        List<int>[] graph = new List<int>[N];
        for (int i = 0; i < N; i++)
            graph[i] = new List<int>();

        bool[] visited = new bool[N];

        for (int i = 0; i < M; i++)
        {
            input = Console.ReadLine().Split();

            int vertex_1 = int.Parse(input[0]);
            int vertex_2 = int.Parse(input[1]);
            graph[vertex_1 - 1].Add(vertex_2 - 1);
            graph[vertex_2 - 1].Add(vertex_1 - 1);
        }

        DFS(graph, visited, 0);

        bool is_connected = true;
        for (int i = 0; i < N; i++)
            if (!visited[i])
                is_connected = false;

        if (is_connected)
            Console.WriteLine(M - N + 1);
        else
            Console.WriteLine(-1);
    }

    static void DFS(List<int>[] graph, bool[] visited, int node)
    {
        visited[node] = true;

        for (int i = 0; i < graph[node].Count; i++)
        {
            if (!visited[graph[node][i]])
                DFS(graph, visited, graph[node][i]);
        }
    }
}