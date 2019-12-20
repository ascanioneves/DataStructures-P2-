#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define maxN 100000

typedef struct heap HEAP;
typedef struct pair PAIR;
typedef struct node NODE;
typedef struct graph GRAPH;

struct pair 
{
    int first; //distance between nodes
    int second; //number of the nodes
};

struct heap 
{
    PAIR data[maxN];
    int size;
};

struct node 
{
    PAIR data;
    NODE *next;
};

struct graph {
    NODE *vertex[maxN];
    bool visited[maxN];
    int size;
};

void print_list(NODE *head) 
{
    NODE *current = head;
    while (current != NULL) 
    {
        printf("(%d, %d) -> ", current->data.first, current->data.second);
        current = current->next;
    }
    printf("\n");
}

void print_graph(GRAPH *graph) 
{
    int i;
    for (i = 0; i < graph->size; ++i) 
    {
        printf("Vertice %d: \n", i);
        print_list(graph->vertex[i]);
    }
}

void swap(PAIR *x, PAIR *y) 
{
    PAIR aux = *x;
    *x = *y;
    *y = aux;
}

int get_parent_index(HEAP *heap, int i) 
{
    return i >> 1; // i/2
}

int get_left_index(HEAP *heap, int i) 
{
    return i << 1; //2*i 
}

int get_right_index(HEAP *heap, int i) 
{
    return (i << 1) + 1; //2*i + 1
}

PAIR item_of(HEAP *heap, int i) 
{
    return heap->data[i];
}

bool is_empty(HEAP *heap) 
{
    return heap->size == 0;
}

GRAPH *create_graph(int number_of_vertex) 
{
    GRAPH *new_graph = (GRAPH*)malloc(sizeof(GRAPH));
    new_graph->size = number_of_vertex;
    int i;
    for (i = 0; i < number_of_vertex; ++i) 
    {
        new_graph->vertex[i] = NULL;
        new_graph->visited[i] = false;
    }
    return new_graph;
}

NODE *create_node(int vertex, int distance) 
{
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    PAIR p;
    p.first = distance, p.second = vertex;
    new_node->data = p;
    new_node->next = NULL;
    return new_node;
}

HEAP *create_heap(int number_of_vertex) 
{
    HEAP *new_heap = (HEAP *) malloc(sizeof(HEAP));
    new_heap->size = 0;
    PAIR p;
    int i;
    for (i = 0; i < number_of_vertex; ++i) 
    {
        p.first = -1;
        p.second = -1;
        new_heap->data[i] = p;
    }
    return new_heap;
}

void enqueue(HEAP *heap, PAIR item) 
{
    if (heap->size >= maxN) 
    {
        printf("Heap Overflow! Cannot enqueue!\n");
    } 
    else 
    {
        heap->data[++heap->size] = item;
        int key_index = heap->size;
        int parent_index = get_parent_index(heap, key_index);
        while (parent_index >= 1 && heap->data[key_index].first < heap->data[parent_index].first) 
        {
            swap(&heap->data[key_index], &heap->data[parent_index]);
            key_index = parent_index;
            parent_index = get_parent_index(heap, key_index);
        }
    }
}

void min_heapify(HEAP *heap, int i) 
{
    int smallest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->data[left_index].first < heap->data[i].first) 
    {
        smallest = left_index;
    } 
    else 
    {
        smallest = i;
    }
    if (right_index <= heap->size && heap->data[right_index].first < heap->data[smallest].first) 
    {
        smallest = right_index;
    }
    if (heap->data[i].first != heap->data[smallest].first) 
    {
        swap(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

PAIR dequeue(HEAP *heap) 
{
    if (is_empty(heap)) 
    {
        printf("Heap Underflow! Cannot dequeue!\n");
        PAIR p; p.first = -1, p.second = -1;
        return p;
    } 
    else 
    {
        PAIR item = heap->data[1];
        heap->data[1] = heap->data[heap->size];
        --heap->size;
        min_heapify(heap, 1);
        return item;
    }
}

void init_visited(GRAPH *graph) {
    int i;
    for (i = 0; i < graph->size; ++i)
        graph->visited[i] = false;
}

NODE *insert_end(NODE *head, int vertex, int distance) 
{
    if (head == NULL)
        return create_node(vertex, distance);
    else 
    {
        NODE *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = create_node(vertex, distance);
        return head;
    }
}

void add_edge(GRAPH *graph, int from, int to, int distance) 
{
    graph->vertex[from] = insert_end(graph->vertex[from], to, distance);
}

void dijkstra(GRAPH *graph, int source, int *distance) 
{
    int i = 0;
    for (i = 0; i < graph->size; ++i) 
        distance[i] = INT_MAX;
    
    distance[source] = 0;
    PAIR p; p.first = 0, p.second = source;
    HEAP *heap = create_heap(graph->size);
    enqueue(heap, p);
    while (!is_empty(heap)) 
    {
        PAIR u = dequeue(heap);
        NODE *current = graph->vertex[u.second];
        while (current != NULL) 
        {
            int actual_dist = distance[u.second] + current->data.first;
            if (actual_dist < distance[current->data.second]) 
            {
                distance[current->data.second] = actual_dist;
                p.first = distance[current->data.second], p.second = current->data.second;
                enqueue(heap, p);
            }
            current = current->next;
        }
    }
}
int main() 
{
    GRAPH *graph = create_graph(10);
    int distance[maxN] = {INT_MAX};
    add_edge(graph, 0, 1, 10);
    add_edge(graph, 1, 2, 10);
    add_edge(graph, 2, 3, 10);
    add_edge(graph, 0, 3, 0);
    add_edge(graph, 0, 2, 5);
    print_graph(graph);
    dijkstra(graph, 0, distance);
    return 0; 
}