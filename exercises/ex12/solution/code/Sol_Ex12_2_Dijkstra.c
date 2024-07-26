#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 20
#define INF 1000

// store the graph in adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];

void dijkstra(int num_v, int start) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    // initialize all vertices: distance to s = inf, visited = 0
    for (int i = 0; i < num_v; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    // looping for all vertices
    for (int iter = 0; iter < num_v - 1; iter++) {
        int minDistance = INF;
        int minIndex = -1;

        // find a unvisited vertices with the smallest distance
        for (int v = 0; v < num_v; v++) {
            if (visited[v]==0 && dist[v] <= minDistance) {
                minDistance = dist[v];
                minIndex = v;
            }
        }
        // unable to reach
        if (dist[minIndex] == INF || minIndex == -1) {
            continue;
        }

        // visit this node
        visited[minIndex] = 1;

        // relaxation
        for (int v = 0; v < num_v; v++) {
            if (visited[v]==1 || v==minIndex || graph[minIndex][v] == INF) {
                continue;
            }
            int new_dist = dist[minIndex] + graph[minIndex][v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < num_v; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d: Unable to reach\n", i);
        }
        else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
        
    }
}

/* Input
5, 10
0, 1, 10
0, 2, 5
1, 2, 2
1, 3, 1
2, 1, 3
2, 3, 9
2, 4, 2
3, 4, 4
4, 0, 7
4, 3, 6
*/
/* Answer
Shortest distances from vertex 0:
Vertex 0: 0
Vertex 1: 8
Vertex 2: 5
Vertex 3: 9
Vertex 4: 7
*/


int main() {
    int num_vertices, num_edges;
    // Enter the number of vertices
    scanf("%d, %d", &num_vertices, &num_edges);

    // set all initial value as infinity, 
    // and set the diagonal to 0
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Enter the edges
    for (int i = 0; i < num_edges; i++) {
        int s, t, w;
        scanf("%d, %d, %d", &s, &t, &w);
        graph[s][t] = w;
    }

    dijkstra(num_vertices, 0);

    return 0;
}