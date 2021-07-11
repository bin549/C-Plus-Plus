#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

namespace graph
{
    template <typename T>
    class Graph
    {
    public:
        Graph() = default;
        ;
        void add_edge(T u, T v, bool bidir = true)
        {
            adjacency_list[u].push_back(v);
            if (bidir == true)
            {
                adjacency_list[v].push_back(u);
            }
        }

        std::map<T, bool> breadth_first_search(T src)
        {
            std::map<T, bool> visited;
            for (auto const &adjlist : adjacency_list)
            {
                visited[adjlist.first] = false;
                for (auto const &node : adjacency_list[adjlist.first])
                {
                    visited[node] = false;
                }
            }
            /// queue to store the nodes which are yet to be traversed
            std::queue<T> tracker;
            /// push the source vertex to queue to begin traversing
            tracker.push(src);
            /// mark the source vertex as visited
            visited[src] = true;
            while (!tracker.empty())
            {
                /// traverse the graph till no connected vertex are left
                /// extract a node from queue for further traversal
                T node = tracker.front();
                /// remove the node from the queue
                tracker.pop();
                for (T const &neighbour : adjacency_list[node])
                {
                    /// check every vertex connected to the node which are still
                    /// unvisited
                    if (!visited[neighbour])
                    {
                        /// if the neighbour is unvisited , push it into the queue
                        tracker.push(neighbour);
                        /// mark the neighbour as visited
                        visited[neighbour] = true;
                    }
                }
            }
            return visited;
        }

    private:
        std::map<T, std::list<T>> adjacency_list;
    };

}

/** Test function */
static void tests()
{
    /// Test 1 Begin
    graph::Graph<int> g;
    std::map<int, bool> correct_result;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    correct_result[0] = true;
    correct_result[1] = true;
    correct_result[2] = true;
    correct_result[3] = true;

    std::map<int, bool> returned_result = g.breadth_first_search(2);

    assert(returned_result == correct_result);
    std::cout << "Test 1 Passed..." << std::endl;

    /// Test 2 Begin
    returned_result = g.breadth_first_search(0);

    assert(returned_result == correct_result);
    std::cout << "Test 2 Passed..." << std::endl;

    /// Test 3 Begins
    graph::Graph<std::string> g2;

    g2.add_edge("Gorakhpur", "Lucknow", false);
    g2.add_edge("Gorakhpur", "Kanpur", false);
    g2.add_edge("Lucknow", "Agra", false);
    g2.add_edge("Kanpur", "Agra", false);
    g2.add_edge("Lucknow", "Prayagraj", false);
    g2.add_edge("Agra", "Noida", false);

    std::map<std::string, bool> correct_res;
    std::map<std::string, bool> returned_res =
        g2.breadth_first_search("Kanpur");
    correct_res["Gorakhpur"] = false;
    correct_res["Lucknow"] = false;
    correct_res["Kanpur"] = true;
    correct_res["Agra"] = true;
    correct_res["Prayagraj"] = false;
    correct_res["Noida"] = true;
    assert(correct_res == returned_res);
    std::cout << "Test 3 Passed..." << std::endl;
}

/** Main function */
int main()
{
    tests();
    size_t edges = 0;
    std::cout << "Enter the number of edges: ";
    std::cin >> edges;

    graph::Graph<int> g;

    std::cout << "Enter space-separated pairs of vertices that form edges: "
              << std::endl;
    while (edges--)
    {
        int u = 0, v = 0;
        std::cin >> u >> v;
        g.add_edge(u, v);
    }

    g.breadth_first_search(0);
    return 0;
}
