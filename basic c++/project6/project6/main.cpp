#include <iostream>
#include <fstream>
#include "mylib.h"


#define range(a, n) ((a >= 0 && a < n) ? "true" : "false")
#define size 4
#define swap(a, b) int c = a; a = b; b = c;

#pragma pack (push,1)
struct employee {
	std::string name;
	size_t yearsOfSeniority;
	size_t positionId;
};
#pragma pack (pop)

int* initArr(int n) {

	int* arr = new int[n];

	std::cout << " please enter " << n << " integer numbers" << std::endl;

	for (int i = 0; i < n; i++) {

		std::cin >> arr[i];
	}
	return arr;
}

int main()
{
	// TASK 1 (+5)

	int n;
	std::cout << "Task1: please enter a size of array" << std::endl;
	std::cin >> n;

	float* arr = mystd::initArr(n);
	mystd::coutArr(arr, n);
	mystd::negativeAndPositive(arr, n);
	delete [] arr;

	// TASK 2

	int a, range;
	std::cout << "Task2: please enter a nuber and aт upper range number" << std::endl;
	std::cin >> a >> range;

	std::cout << range(a, range) << std::endl;

	// TASK 3

	std::cout << "Task3: ";
	
	int* arrSort = initArr(size);

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - 1; j++) {

			if (arrSort[j] > arrSort[j + 1]) {
				swap(arrSort[j + 1], arrSort[j]);
			}
		}
	}
	 
	std::cout << "after sort: ";

	for (int i = 0; i < size; i++) {

		std::cout << arrSort[i] << " ";
	}
	std::cout << std::endl;

	delete[] arrSort;

	// TASK 4

	employee* emp1 = new employee;

	emp1->name = "Kostya";
	emp1->yearsOfSeniority = 5;
	emp1->positionId = 345;

	std::cout << "Task4: size of struct employy: " << sizeof(emp1) << std::endl;
	std::cout << "Name: " << emp1->name << std::endl;
	std::cout << "Years of seniority: " << emp1->yearsOfSeniority << std::endl;
	std::cout << "Position ID: " << emp1->positionId << std::endl;

	std::ofstream fout;
	fout.open("employee.txt");
	fout << "Name: " << emp1->name << std::endl;
	fout << "Years of seniority: " << emp1->yearsOfSeniority << std::endl;
	fout << "Position ID: " << emp1->positionId << std::endl;
	fout.close();

	delete emp1;
}