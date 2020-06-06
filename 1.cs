using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split(' ');
        int N = int.Parse(input[0]);
        int M = int.Parse(input[1]);
        Dictionary<int, List<int>> graph = new Dictionary<int, List<int>>();
        bool[] visited_vertices = new bool[N];

        for (int i = 1; i <= N; i++)
        {
            graph[i] = new List<int>();
        }

        for (int i = 0; i < M; i++)
        {
            input = Console.ReadLine().Split();
            graph[int.Parse(input[0])].Add(int.Parse(input[1]));
            graph[int.Parse(input[1])].Add(int.Parse(input[0]));
        }

        int components = 0;

        for (int i = 1; i <= N; i++)
        {
            if (!visited_vertices[i - 1])
            {
                DFS(i, graph, visited_vertices);
                components++;
            }
        }

        Console.WriteLine(components - 1);
    }

    static void DFS(int vertex, Dictionary<int, List<int>> graph, bool[] visited_vertices)
    {
        visited_vertices[vertex - 1] = true;
        
        foreach (int neighbour in graph[vertex])
        {
            if (!visited_vertices[neighbour - 1])
            {
                DFS(neighbour, graph, visited_vertices);
            }
        }
    }
}