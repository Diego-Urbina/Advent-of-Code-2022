#pragma once

#include <limits>
#include <vector>

namespace utils
{
namespace graphs
{
inline std::vector<int> dijkstra(const std::vector<std::vector<int>> &graph, int src)
{
    size_t graph_size = graph.size();

    std::vector<int> distances(graph_size, std::numeric_limits<int>::max());
    std::vector<bool> visited_nodes(graph_size, false);

    distances[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < graph_size - 1; count++) {

        int min = std::numeric_limits<int>::max();
        int u = 0;

        for (int v = 0; v < distances.size(); v++) {
            if (visited_nodes[v] == false && distances[v] <= min) {
                min = distances[v];
                u = v;
            }
        }

        // Mark the picked vertex as processed
        visited_nodes[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < graph_size; v++) {

            // Update distances[v] only if is not in visited_nodes,
            // there is an edge from u to v, and total
            // weight of path from src to v through u is
            // smaller than current value of distances[v]
            if (!visited_nodes[v] && graph[u][v] &&
                distances[u] != std::numeric_limits<int>::max() &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }

    return distances;
}
}
}