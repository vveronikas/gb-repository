#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

template<class T, typename Container>
void insert_sorted(Container& cont, T& n)
{
	for (auto i = cont.begin(); i < cont.end(); i++)
	{
		if (std::next(i) != cont.end()) 
		{
			if ((*i < n && *std::next(i) > n) || (*i > n && *std::next(i) < n) || (*i == n))
			{
				cont.insert(std::next(i), n);
				break;
			}
		}
		else
		{
			cont.insert(std::next(i), n);
			break;
		}
	}
}

int main()
{
	/* 1. Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
	которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
	чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted,
	которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.*/

	std::vector<int> v { 1, 2, 3, 4, 5, 8, 9};
	int n = 6;
	insert_sorted(v, n);
	for (auto i : v)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::deque<double> deq{ 5.4, 4.1, 3.4, 1.1};
	double d = 2.4;
	insert_sorted(deq, d);
	for (auto i : deq)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	/* 2. Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой значения аналогового сигнала.
	На основе этого массива чисел создайте другой вектор целых чисел b, представляющий цифровой сигнал, в котором будут 
	откинуты дробные части чисел. Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой сигнал 
	по сравнению с аналоговым по формуле:*/

	std::vector<double> s1(100);
	std::generate(s1.begin(), s1.end(), []() { return rand() / 100.1; });
	for_each(s1.begin(), s1.end(), [](double i) { std::cout << i << " "; });
	std::cout << std::endl;

	std::vector<int> s2(100);
	for_each(s1.begin(), s1.end(), [&s2](int i) {s2.push_back((int)i); std::cout << i << " "; });
	std::cout << std::endl;

	auto it1 = s1.begin();
	auto it2 = s2.begin();
	double err = 0;

	while (it1 != s1.end() && it2 != s2.end())
	{
		err += std::pow(*it1 - *it2, 2);
		it1++;
		it2++;
	}
	std::cout << "err = " << err << std::endl;
}