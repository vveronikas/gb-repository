#include <iostream>
#include <vector>

struct Node
{
	double data;
	Node* next;
};

class MyList
{
public:
	MyList() 
	{
		head = NULL;
		size = 0;
	}
	~MyList()
	{
		Node* current = new Node;
		Node* nextNode = new Node;
		current = head;
		if (current != NULL)
		{
			while (current->next != NULL)
			{
				nextNode = current->next;
				head = nextNode;
				size--;
				delete current;
				current = nextNode;
			}
		}
		delete nextNode;
	}
	void push_back(double data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;

		Node* current = new Node;
		current = head;
		if (current == NULL)
		{
			head = newNode;
			size++;
		}
		else
		{
			while (current->next != NULL)
				current = current->next;
			current->next = newNode;
			size++;
		}
	}
	void push_back()
	{
		double sum = 0;
		Node* current = new Node;
		current = head;
		if (current == NULL)
		{
			std::cout << "List is empty" << std::endl;
		}
		else
		{
			do
			{
				sum += current->data;
				current = current->next;
			} while (current != NULL);
			(*this).push_back(sum / size);
		}
	}
	friend std::ostream& operator<< (std::ostream& out, MyList& lst);
protected:
	Node* head;
	int size;
};

std::ostream& operator<< (std::ostream& out, MyList& lst)
{
	Node* current = new Node;
	current = lst.head;
	if (current == NULL)
	{
		out << "List is empty" << std::endl;
	}
	else
	{
		do
		{
			out << current->data << " ";
			current = current->next;
		} while (current != NULL);

		out << std::endl;
	}
	return out;
}

class Matrix
{
public:
	Matrix() {};
	Matrix(int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::vector<int> tmp;
			for (int j = 0; j < size; j++)
			{
				tmp.push_back(0);
			}
			matrix.push_back(tmp);
		}
	};
	~Matrix() {};
	void random_init(int size)
	{
		for (int i = 0; i < size; i++)
		{
			std::vector<int> tmp;
			for (int j = 0; j < size; j++)
			{
				tmp.push_back(rand() % 10);
			}
			matrix.push_back(tmp);
		}
	}
	int get_size() { return matrix.size(); }
	std::vector<std::vector<int>> get_matrix() { return matrix; }
	int findDet(std::vector<std::vector<int>> a, int n) {
		if (n == 1)
			return a[0][0];
		else if (n == 2)
			return a[0][0] * a[1][1] - a[0][1] * a[1][0];
		else {
			int d = 0;
			Matrix mat(n);
			std::vector<std::vector<int>> m = mat.get_matrix();
			for (int k = 0; k < n; k++) {
				for (int i = 1; i < n; i++) {
					int t = 0;
					for (int j = 0; j < n; j++) {
						if (j == k)
							continue;
						m[i - 1][t] = a[i][j];
						t++;
					}
				}
				d += pow(-1, k + 2) * a[0][k] * findDet(m, n - 1);
			}
			return d;
		}
	}
	friend std::ostream& operator<< (std::ostream& out, Matrix& m);
protected:
	std::vector<std::vector<int>> matrix;
};

std::ostream& operator<< (std::ostream& out, Matrix& m)
{
	for (auto i : m.matrix)
	{
		for (auto j : i)
		{
			out << j << " ";
		}
		out << std::endl;
	}
	return out;
}

class MyIter
{
public:
	MyIter() {};
	MyIter(int& val) { Ptr = &val; };
	void operator=(int val) { *Ptr = val; }
	int operator*() { return *Ptr; }
	void operator++() { Ptr++; }
private:
	int* Ptr;
};

int main()
{
    // 1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, 
    // значение которого равно среднему арифметическому всех его элементов.
	MyList lst;
	lst.push_back(1.2);
	lst.push_back(1.5);
	lst.push_back();
	std::cout << lst;
	
    // 2. Создать класс, представляющий матрицу. Реализовать в нем метод, вычисляющий определитель матрицы. 
    // Для реализации используйте контейнеры из STL.
	Matrix m;
	m.random_init(3);
	std::cout << m << std::endl;
	std::cout << "det: " << m.findDet(m.get_matrix(), m.get_size()) << std::endl;

    // 3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться 
    // по диапазону целых чисел в цикле for-range-based.

	int A[3] = { 1, 2, 3 };
	for (MyIter i : A)
		std::cout << *i << " ";
}
