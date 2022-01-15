// project10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
}

void printList(List* lst)
{
	Node* current = new Node;
	current = lst->head;
	if (current == NULL)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		do
		{
			std::cout << current->data;
			current = current->next;
		} while (current != NULL);

		std::cout << std::endl;
	}
}

List* permutationEncryption(List* lst, int n)
{
	if (lst->size % n != 0)
	{
		std::cout << "String size is not a multiple of the number of columns! Please try again" << std::endl;
		return NULL;
	}
	Node* current = new Node;
	current = lst->head;

	char** matrix = new char* [n];
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new char[lst->size / n];
	}

	int j = 0;
	do
	{
		for (size_t i = 0; i < n; i++)
		{
			matrix[i][j] = current->data;
			current = current->next;
		}
		j++;
	} while (current != NULL);

	List* cipherLst = new List;
	init(cipherLst);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < lst->size / n; j++)
		{
			ins(cipherLst, matrix[i][j]);
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	std::cout << "Permutation encryption : ";
	printList(cipherLst);
	return cipherLst;
}

List* permutationDecoding(List* lst, int n)
{
	if (lst == NULL)
	{
		std::cout << "List is empty" << std::endl;
		return NULL;
	}
	if (lst->size % n != 0)
	{
		std::cout << "String size is not a multiple of the number of columns! Please try again" << std::endl;
		return NULL;
	}
	Node* current = new Node;
	current = lst->head;

	char** matrix = new char* [lst->size / n];
	for (size_t i = 0; i < lst->size / n; i++)
	{
		matrix[i] = new char[n];
	}

	int j = 0;
	do
	{
		for (size_t i = 0; i < lst->size / n; i++)
		{
			matrix[i][j] = current->data;
			current = current->next;
		}
		j++;
	} while (current != NULL);

	List* cipherLst = new List;
	init(cipherLst);
	for (size_t i = 0; i < lst->size / n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			ins(cipherLst, matrix[i][j]);
		}
	}

	for (size_t i = 0; i < lst->size / n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	std::cout << "Permutation decoding : ";
	printList(cipherLst);
	return cipherLst;
}

List* caesarEncryption(List* lst, int n)
{
	if (n > 26) n % 26;
	List* cipherLst = new List;
	init(cipherLst);
	Node* current = new Node;
	current = lst->head;

	do {
		if (current->data + n > 122)
			ins(cipherLst, (current->data + n) - 26);
		else
			ins(cipherLst, current->data + n);
		current = current->next;
	} while (current != NULL);

	std::cout << "Caesar encryption: ";
	printList(cipherLst);
	return cipherLst;
}

List* caesarDecoding(List* lst, int n)
{
	if (n > 26) n % 26;
	List* cipherLst = new List;
	init(cipherLst);
	Node* current = new Node;
	current = lst->head;

	do {
		if (current->data - n < 97)
			ins(cipherLst, 26 + (current->data - n));
		else
			ins(cipherLst, current->data - n);
		current = current->next;
	} while (current != NULL);

	std::cout << "Caesar decoding: ";
	printList(cipherLst);
	return cipherLst;
}

int main()
{
	// Реализовать шифрование и расшифровку перестановками с передаваемым в функцию сообщением и количеством столбцов
	std::cout << "Please enter a string." << std::endl;
	List* lst = new List;
	init(lst);
	char ch = '\n';
	do
	{
		std::cin >> std::noskipws >> ch;
		if (ch != '\n') ins(lst, ch);

	} while (ch != '\n');

	std::cout << "Please enter a number" << std::endl;
	int n;
	std::cin >> n;

	List* cipherList = new List;
	init(cipherList);

	cipherList = permutationEncryption(lst, n);
	permutationDecoding(cipherList, n);

	// Реализовать шифрование и расшифровку цезаря с передаваемым в функцию сообщением и ключом

	cipherList = caesarEncryption(lst, n);
	caesarDecoding(cipherList, n);

	deleteList(lst);
	deleteList(cipherList);
}