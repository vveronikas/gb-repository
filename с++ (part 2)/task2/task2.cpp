#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <chrono>

template <class T> 
void swap(T** ptr1, T** ptr2)
{
	T** ptr3 = new int*;
	*ptr3 = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr3;
}

template <class T>
void SortPointers(std::vector<T*>& v)
{
	for (auto& i : v)
	{
		for (auto& j : v)
		{
			if (*i < *j) swap(&i, &j);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	// task 1
	int* a = new int;
	*a = 5;
	int* b = new int;
	*b = 6;
	std::cout << "ptr1: " << a << " value: " << *a << std::endl;
	std::cout << "ptr2: " << b << " value: " << *b << std::endl;
	swap(&a, &b);
	std::cout << " After swap: " << std::endl;
	std::cout << "ptr1: " << a << " value: " << *a << std::endl;
	std::cout << "ptr2: " << b << " value: " << *b << std::endl;

	// task 2
	int* c = new int;
	*c = 1;
	std::vector<int*> v {b, a, c};
	SortPointers(v);
	for (auto& i : v)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	// task 3
	std::ifstream file("book.txt");
	std::string str;
	std::string vowels{ "euoaiEUOAI" };
	size_t count = 0;
	
	auto start = std::chrono::steady_clock::now();
	while (!file.eof()) {
		std::getline(file, str);
		count += std::count_if(str.begin(), str.end(), [&vowels](char ch)
			{
				if (vowels.find(ch) != std::string::npos) return true;
				else return false; 
			});
	}
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> Time = end - start;
	std::cout << "count_if and find : " << Time.count() * 1000 << "msec" << std::endl;
	std::cout << count << std::endl;
	file.close();

	count = 0;
	std::ifstream file2("book.txt");
	start = std::chrono::steady_clock::now();
	while (!file2.eof()) {
		std::getline(file2, str);
		count += std::count_if(str.begin(), str.end(), [&vowels](char ch)
			{
				for (auto i : vowels)
					if (ch == i) return true;
				return false;
			});
	}
	end = std::chrono::steady_clock::now();
	Time = end - start;
	std::cout << "count_if and for : " << Time.count() * 1000 << "msec" << std::endl;
	std::cout << count << std::endl;
	file2.close();


	count = 0;
	std::ifstream file3("book.txt");
	start = std::chrono::steady_clock::now();
	while (!file3.eof()) 
	{
		std::getline(file3, str);
		for (auto i : str)
		{
			if (vowels.find(i) != std::string::npos)
				count++;
		}
	}
	end = std::chrono::steady_clock::now();
	Time = end - start;
	std::cout << "for and find : " << Time.count() * 1000 << "msec" << std::endl;
	std::cout << count << std::endl;
	file3.close();

	count = 0;
	std::ifstream file4("book.txt");
	start = std::chrono::steady_clock::now();
	while (!file4.eof()) {
		std::getline(file4, str);
		for (auto i : str)
		{
			for (auto j : vowels)
				if (i == j) count++;
		}
	}
	end = std::chrono::steady_clock::now();
	Time = end - start;
	std::cout << "for and for : " << Time.count() * 1000 << "msec" << std::endl;
	std::cout << count << std::endl;
	file4.close();
}