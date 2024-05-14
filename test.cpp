#include <iostream>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/floyd_warshall_shortest.hpp>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;

int main() {
    // Define the number of vertices
    const int num_vertices = 9;

    // Define the edges and their weights
    std::pair<int, int> edges[] = {
        {0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
        {0, 3}, {3, 6}, {2, 5}, {5, 8},
        {1, 3}, {1, 5}, {4, 7}, {3, 7}
    };
    int weights[] = {
        200, 200, 200, 200, 200, 200,
        150, 150, 150, 150,
        250, 250, 250, 250,
        150, 150
    };

    // Create a graph
    boost::adjacency_matrix<boost::undirectedS, int> graph(num_vertices);

    // Add the edges to the graph
    for (int i = 0; i < sizeof(edges)/sizeof(edges[0]); ++i) {
        boost::add_edge(edges[i].first, edges[i].second, weights[i], graph);
    }

    // Create a matrix to store the shortest distances
    boost::adjacency_matrix<boost::directedS, int> distance_matrix(num_vertices);

    // Run the Floyd-Warshall algorithm
    boost::floyd_warshall_all_pairs_shortest_paths(graph, distance_matrix);

    // Define the vertices
    std::vector<int> vertices = {0, 1, 2, 4, 6, 7, 8};

    // Initialize the minimum distance with a large number
    int min_distance = std::numeric_limits<int>::max();

    // Iterate over all permutations of the vertices
    do {
        // Start at 3 and end at 5
        vertices.insert(vertices.begin(), 3);
        vertices.push_back(5);

        // Calculate the total distance of the route
        int distance = 0;
        for (int i = 0; i < vertices.size() - 1; ++i) {
            distance += distance_matrix[vertices[i]][vertices[i+1]];
        }

        // Update the minimum distance
        if (distance < min_distance) {
            min_distance = distance;
        }

        // Remove 3 and 5 from the vertices
        vertices.erase(vertices.begin());
        vertices.pop_back();
    } while (std::next_permutation(vertices.begin(), vertices.end()));

    // Print the minimum distance
    std::cout << min_distance << std::endl;

    return 0;
}