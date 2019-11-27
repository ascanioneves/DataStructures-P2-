#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//LIFO : Last In, First Out
//Só podemos acessar o último elemento adicionado na pilha
//Principais operações:
// (ADT):
// Pop() : Apaga logicamente o último elemento
// Push() : Adiciona um elemento no topo da pilha
// Peek ou Top : Retorna o elemento do topo da pilha
// isEmpty() : retorna o estado da pilha (true se está vazia, false se não está)

#define maxN 10

typedef struct Stack Stack;

//const int maxN = 10;

struct Stack
{
	int size;
	int items[maxN];
};

bool isEmpty(Stack *stk)
{
	return (stk->size == 0);
}

Stack* createStack()
{
	Stack *new_stack = (Stack *) malloc(sizeof(Stack)); //alocando espaço com o tamanho da struct pilha
	new_stack->size = 0;
	return new_stack;
}

void pop(Stack *stk)
{
	/*
	if(isEmpty(stk))
		return; 
	*/
	--stk->size;
	return;
}

void push(Stack *stk, int item)
{
	if(stk->size == maxN)
		printf("Stack Overflow\n");
	else
	{
		stk->items[stk->size] = item;
		++stk->size;
	}
}

int top(Stack *stk)
{
	return stk->items[stk->size-1];
}

void printStack(Stack* stk)
{
	for(int i = 0; i < stk->size; i++)
		printf("%d ", stk->items[i]);
	putchar('\n');
}

int main()
{
	Stack *stk  = createStack();
	push(stk, 1);
	push(stk, 2);
	push(stk, 3);
	printf("Pilha antes da remoção: \n");
	printStack(stk);
	printf("Elemento do topo da pilha : \n%d\n", top(stk));
	printf("Pilha após remoção de 1 elemento:\n");
	pop(stk);
	printStack(stk);
	return 0;
}