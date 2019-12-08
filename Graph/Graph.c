#include <stdio.h>
#include <stdlib.h>

// -------------- GUIDE -------------- //
/*
Graph is a not linear structure
Definition : A Graph is a ordered pair G = (V, E) : "A set of vertices and edges"
An Edge is related to two vertices
--- We have two types of graphs: ----
--> Undirected graphs (without direction)
--> Directed graphs (with direction)

Representation:
Adjacency List versus Adjacency Matrix

We have the following ADT:
add_egde() -> add an edge to graph
dfs() -> searching graph algorithm (Depth First Search)
bfs() -> searching graph algorithm (Breadth First Search)

*/

#define maxN 10

typedef struct Adj Adj;

//Adjacency List
//The item is the number of node
struct Adj
{ 
  int item;
  Adj *next;
};

typedef struct Graph
{
  Adj *vertices[maxN];
  short visited[maxN];
}Graph;

Graph* create_graph()
{
  Graph *new_graph = (Graph *) malloc(sizeof(Graph));
  int i;
  for(i = 1; i <= maxN - 1; i++)
  {
    new_graph -> vertices[i] = NULL;
    new_graph -> visited[i] = 0;
  }
  return new_graph;
}

Adj* create_adj_list(int item)
{
  Adj *new_adj_list = (Adj *) malloc(sizeof(Adj));
  new_adj_list -> item = item;
  new_adj_list -> next = NULL;
  return new_adj_list;
}

void add_edge(Graph *graph, int vertex1, int vertex2)
{ 
  Adj *vertex = create_adj_list(vertex2);
  vertex -> next = graph -> vertices[vertex1];
  graph -> vertices[vertex1] = vertex; //new head

  //The following code is necessally if you have an undirected graph
  vertex = create_adj_list(vertex1);
  vertex -> next = graph -> vertices[vertex2];
  graph -> vertices[vertex2] = vertex;
}

void print_graph(Graph *graph)
{
  for(int i = 1; i <= maxN; i++)
  {
    if(graph -> vertices[i] != NULL)
    {
      printf("Adjacency list of %d : ", i);
      while(graph -> vertices[i] != NULL)
      {
        printf("%d ", graph -> vertices[i] -> item);
        graph -> vertices[i] = graph -> vertices[i] -> next;
      }
      printf("\n");
    }
  }
}

int main()
{
  Graph *undirected_graph = create_graph();

  add_edge(undirected_graph, 1 , 2);
  add_edge(undirected_graph, 1 , 3);
  add_edge(undirected_graph, 2 , 3);
  add_edge(undirected_graph, 3 , 4);

  print_graph(undirected_graph);

  return 0;
}
