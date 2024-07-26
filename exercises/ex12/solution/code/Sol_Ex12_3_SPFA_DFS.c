#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define INF 1000


struct Edge {
	int dest; // destination of the edge
	int weight;
};

struct Graph {
	int num_vertices;
	// idx_1: current vertex
    // idx_2: index of edges start from current vertex
	struct Edge array[MAX_VERTICES][MAX_VERTICES];
};


struct Graph createGraph(int num_vertices) {
    struct Graph graph;
    graph.num_vertices = num_vertices;

    // initialize
    for (int i = 0; i < num_vertices; ++i) {
        for (int j = 0; j < num_vertices; ++j) {
            graph.array[i][j].dest = -1;
            graph.array[i][j].weight = 0;
        }
    }
    return graph;
}


void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // find the insert point
    int i = 0;
    while (graph->array[src][i].dest != -1)
        ++i;
    
    graph->array[src][i].dest = dest;
    graph->array[src][i].weight = weight;
}


int dist[MAX_VERTICES];
int instack[MAX_VERTICES];

/**
 * This is an example for the DFS-based method
*/
int spfa(struct Graph* graph, int u) {
    instack[u] = 1;

    // iterate all edegs starting from u
    int edge_idx = 0;
    while(graph->array[u][edge_idx].dest != -1) {
        int v = graph->array[u][edge_idx].dest;
        int weight = graph->array[u][edge_idx].weight;
        
        // relaxation
        int new_dist = dist[u] + weight;
        if (new_dist < dist[v]){
            dist[v] = new_dist;

            if (instack[v] == 0) {
                if (spfa(graph, v) == -1)
                    return -1;
            }
            else {
                // v already in the exploring chain -> negative cycle
                return -1;
            }
        }
        edge_idx++;
    }
    instack[u] = 0;
    return 0;
    
}


/* Input
5, 8
0, 1, -1
0, 2, 4
1, 2, 3
1, 3, 3
1, 4, 2
3, 1, 1
3, 2, 5
4, 3, -3
*/

/* Input - negative cycle
5, 8
0, 1, -1
0, 2, 4
1, 2, 3
1, 3, 3
1, 4, 2
3, 1, 1
2, 3, -5
4, 3, -3
*/

int main(){
    int num_vertices, num_edges;
    // Enter the number of vertices
    scanf("%d, %d", &num_vertices, &num_edges);

    struct Graph graph = createGraph(num_vertices);

    // Enter the edges
    for (int i = 0; i < num_edges; i++) {
        int from, to, w;
        scanf("%d, %d, %d", &from, &to, &w);
        // direct
        addEdge(&graph, from, to, w);
    }

    int num_v = graph.num_vertices;
    int start = 0;
    // initialize all vertices: distance to s as infinity and visited as 0
    for (int i = 0; i < num_v; i++) {
        dist[i] = INF;
        instack[i] = 0;
    }
    dist[start] = 0;

    if (spfa(&graph, start) == -1){
        printf("Graph contains a negative cycle.");
    }
    else {
        printf("Shortest distances from vertex %d:\n", start);
        for (int i = 0; i < num_v; i++) {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
    
    return 0;
}