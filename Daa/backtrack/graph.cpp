#include <iostream>
using namespace std;

// Function to check if it is safe to color vertex v with color c
bool isSafe(int v, bool graph[101][101], int color[], int c, int V) {
    // Check all adjacent vertices
    for (int i = 0; i < V; i++) {
        // If there is an edge between v and i, and they both have the same color, return false
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Backtracking function to solve graph coloring problem
bool graphColoringUtil(bool graph[101][101], int m, int color[], int v, int V) {
    // Base case: If all vertices are assigned a color, return true
    if (v == V)
        return true;

    // Try assigning different colors to this vertex
    for (int c = 1; c <= m; c++) {
        // Check if assigning color c to vertex v is possible
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c;  // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;  // Remove the color assignment
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

// Function to solve the graph coloring problem using backtracking
bool graphColoring(bool graph[101][101], int m, int V) {
    int color[101] = {0};  // Initialize all vertices as uncolored (0)

    // Call the utility function to solve the problem starting from the first vertex (v = 0)
    if (!graphColoringUtil(graph, m, color, 0, V)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    // Print the solution (color assigned to each vertex)
    cout << "Solution exists with the following colors:" << endl;
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " --->  Color " << color[i] << endl;

    return true;
}

int main() {
    int V;  // Number of vertices
    int E;  // Number of edges
    int m;  // Number of colors

    // Read the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create a 2D array (adjacency matrix) to represent the graph
    bool graph[101][101] = {false};

    cout << "Enter the edges (u v) where there is an edge between u and v:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    // Read the number of colors
    cout << "Enter the number of colors: ";
    cin >> m;

    // Solve the graph coloring problem
    graphColoring(graph, m, V);

    return 0;
}
