// project5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#define SIZE 1000

struct Node {
	int pr;
	int dat;
};

void insert(int pr, int dat, int * items, int* tail, Node * arr)
{
	Node* node = new Node;
	node->pr = pr;
	node->dat = dat;

	if (*items < SIZE)
	{
		arr[(*tail)++] = *node;
		(*items)++;
	}
	else
	{
		std::cout << "Queue is full" << std::endl;
	}
}

Node* rem(int* items, int* tail, Node* arr)
{
	if (*items == 0)
	{
		std::cout << "Queue is empty" << std::endl;
		return NULL;
	}
	
	int max = arr[0].pr;
	int idx = 0;

	for (size_t i = 0; i < *items; i++)
	{
		if (arr[i].pr > max)
		{
			max = arr[i].pr;
			idx = i;
		}
	}

	Node* tmp = new Node;
	*tmp = arr[idx];

	while (idx < *items) 
	{
		arr[idx] = arr[idx + 1];
		idx++;
	}
	(*items)--;
	(*tail)--;
	return tmp;
}

int pushStack(int n, int* stack, int* cursor)
{
	if (*cursor < SIZE) {
		stack[++(*cursor)] = n;
		return 1;
	}
	else {
		std::cout << "Stack overflow" << std::endl;
		return 0;
	}
}

int popStack(int *stack, int *cursor)
{
	if (*cursor != -1) {
		return stack[(*cursor)--];
	}
		
	else
	{
		std::cout << "Stack is empty" << std::endl;
		return -1;
	}
}

void decToBin(int n)
{
	int* cursor = new int;
	*cursor = -1;
	int* stack = new int[SIZE];

	std::cout << n << " ";

	while (n >= 1)
	{
		pushStack(n % 2, stack, cursor);
		n = n / 2;
	}

	while (*cursor != -1)
	{
		std::cout << popStack(stack, cursor);
	}

	std::cout << std::endl;

	delete[] stack;
	delete cursor;
}

int main()
{
   // Реализовать перевод из десятичной в двоичную систему счисления с использованием стека

	decToBin(7);

	// Описать очередь с приоритетным исключением

	int* tail = new int;
	*tail = 0;
	int* items = new int;
	*items = 0;
	Node* arr = new Node[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i].pr = NULL;
		arr[i].dat = NULL;
	}

	insert(2, 3, items, tail, arr);
	insert(10, 2, items, tail, arr);
	insert(4, 5, items, tail, arr);
	insert(3, 7, items, tail, arr);

	rem(items, tail, arr);
	rem(items, tail, arr);

	for (size_t i = 0; i < *items; i++)
	{
		std::cout << arr[i].dat << " ";
	}
	std::cout << std::endl;

	delete[] arr;
	delete tail;
	delete items;
}

