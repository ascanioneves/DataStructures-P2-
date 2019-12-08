#include <stdio.h>
#include <stdlib.h>

#define maxN 10

//estrutura básica da fila
typedef struct Queue
{
  int current_size; //tamanho atual da fila
  int tail; //cauda atual da fila
  int head; //cabeça atual da fila
  int items[maxN]; //itens da fila 
}Queue;

Queue* create_queue()
{
  Queue *new_queue = (Queue *) malloc(sizeof(Queue));
  new_queue -> current_size = 0;
  new_queue -> tail = maxN - 1;
  new_queue -> head = 0;
  return new_queue;
}

//colocamos no final
void enqueue(Queue *queue, int item)
{
  //caso a fila esteja cheia  
  if(queue -> current_size == maxN)
    printf("Queue is full!\n");
  else
  {
    queue -> tail = (queue -> tail + 1) % maxN; //fila circular, evita que ultrapasse os limites da fila
    queue -> items[queue -> tail] = item;
    ++queue -> current_size;
  }
  
}

//First in First Out, ou seja, na remoção, retiramos a cabeça da fila
void dequeue(Queue *queue)
{
  int dequeued = queue -> items[queue -> head];
  queue -> head = (queue -> head + 1) % maxN;
  --queue -> current_size;
}

int main()
{
  Queue *queue = create_queue();

  return 0;
}