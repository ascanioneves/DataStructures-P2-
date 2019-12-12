#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 100

typedef struct Adj Adj;

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
  Graph* new_graph = (Graph *) malloc(sizeof(Graph));
  int i;
  for(i = 1; i <= maxN; i++)
  {
    new_graph -> vertices[i] = NULL;
    new_graph -> visited[i] = 0;
  }
  return new_graph;
}

Adj* create_adj_list(int item)
{
  Adj *new_adj = (Adj *) malloc(sizeof(Adj));
  new_adj -> item = item;
  new_adj -> next = NULL;
  return new_adj;
}

void add_edge(Graph *graph, int vertex1, int vertex2)
{
  Adj *vertex = create_adj_list(vertex2);
  vertex -> next = graph -> vertices[vertex1];
  graph -> vertices[vertex1] = vertex;
  //if the graph is undirected:
  /*
  vertex = create_adj_list(vertex1);
  vertex -> next = graph -> vertices[vertex2];
  graph -> vertices[vertex2] = vertex;
  */
}

void dfs(Graph *graph, int source)
{
  graph -> visited[source] = 1;
  printf("%d\n", source);
  Adj *adj_list = graph -> vertices[source];
  while(adj_list != NULL)
  {
    if(!graph -> visited[adj_list -> item])
      dfs(graph, adj_list->item);
    adj_list = adj_list -> next;
  }
}

int main()
{
  Graph *graph = create_graph();
  add_edge(graph, 1, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 2, 4);
  add_edge(graph, 2, 5);
  add_edge(graph, 3, 6);
  dfs(graph, 1);
  return 0;
}