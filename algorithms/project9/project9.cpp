// project9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node
{
	char data;
	Node* next;
};

struct List
{
	Node* head;
	int size;
};

void init(List* lst)
{
	lst->head = NULL;
	lst->size = 0;
}

void ins(List* lst, char data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node* current = new Node;
	current = lst->head;
	if (current == NULL)
	{
		lst->head = newNode;
		lst->size++;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		lst->size++;
	}
}

void deleteList(List* lst)
{
	Node* current = new Node;
	Node* nextNode = new Node;
	current = lst->head;
	while (current->next != NULL)
	{
		nextNode = current->next;
		lst->head = nextNode;
		lst->size--;
		delete current;
		current = nextNode;
	}
	delete nextNode;
	delete lst;
}

unsigned long long hash(List* lst)
{
	Node* current = new Node;
	current = lst->head;
	unsigned long long sum = 0;
	for (int i = lst->size - 1; i >=0 ; i--)
	{
		sum += pow(current->data, i);
		current = current->next;
	}
	return sum;
}

void sumCoins(int totalSum)
{
	int coins[5] = { 50, 10, 5, 2, 1 };
	int sum = 0;
	int count = 0;
	int i = 0;
	while (sum != totalSum)
	{
		if (totalSum - sum < coins[i])
		{
			i++;
			continue;
		}

		sum += coins[i];
		count++;
		std::cout << coins[i] << " ";
	}
	std::cout << std::endl << "total amount of coins = " << count << std::endl;
}

int main()
{
	// Реализовать простейшую хеш - функцию.На вход функции подается строка, на выходе сумма кодов символов.
	std::cout << "Please enter a string (A-Z, a-z, max length = 10)." << std::endl;
	List* lst = new List;
	init(lst);
	char ch = '\n';
	do 
	{
		std::cin >> std::noskipws >> ch;
		if (ch != '\n') ins(lst, ch);

	} while (ch != '\n');

	std::cout << "hash = " << hash(lst) << std::endl;
	deleteList(lst);

	// Имеются монеты номиналом 50, 10, 5, 2, 1 коп. 
	// Напишите функцию которая минимальным количеством монет наберет сумму 98 коп. 
	// Для решения задачи используйте “жадный” алгоритм.

	sumCoins(98);
}