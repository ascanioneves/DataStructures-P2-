#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
	int item;
	Node *next;
};

//Função que cria a lista inicialmente apontando pro nulo
Node* createLinkedList()
{
	return NULL;
}
//Função que verifica se a lista está vazia
bool isEmpty(Node *head)
{
	return (head == NULL);
}

//adicionando um elemento na lista
//Lembrar que a inserção na lista é do começo, ou seja, quando é adicionado um elemento ele vai pro
//começo da lista
Node* add(Node *head, int item)
{
	Node *new_node = (Node *) malloc(sizeof(Node)); //alocando o espaço pra um nó
	new_node -> item = item;
	new_node -> next = head;
	return new_node;
}

void removeNode(Node *head, int item)
{
	Node *previous = NULL;
	Node *current = head;
	while(current != NULL && current -> item != item)
	{
		previous = current;
		current = current -> next;
	}
	if(current == NULL)
		return;
	if(previous == NULL)
		head = current -> next;
	else
		previous -> next = current -> next;
	free(current);
	return;
}

//This Search Function is not general
Node* search(Node *head, int item)
{
	while(head != NULL)
	{
		if(head -> item == item)
			return head;
		head = head -> next;
	}
	return NULL;
}

//Função para printar a lista
void printList(Node *head)
{
	while(head != NULL)
	{
		printf("%d\n", head -> item);
		head = head -> next;
	}
}

int main()
{
	Node* list = createLinkedList();
	
	list = add(list, 3);
	list = add(list, 2); //essa atribuição serve para atualizar a cabeça da lista
	list = add(list, 1);

	printf("Complete List : \n");
	printList(list);
	removeNode(list, 2);
	printf("After remove 2:\n");
	printList(list);
	Node* ans = search(list, 3);

	if(ans == NULL)
		printf("Not found!\n");

	else
		printf("3 was found!\n");
	return 0;
}