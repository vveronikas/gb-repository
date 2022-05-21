#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>

template<class T>
void unique_str(T beg, T en)
{
	std::set<std::string> unique;
	std::for_each(beg, en, [&unique](std::string str) {unique.insert(str); });
	std::for_each(unique.begin(), unique.end(), [](std::string str) {std::cout << str << " "; });
	std::cout << std::endl;
}

int main()
{
	/* 1. Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов,
	и выводящую в консоль список уникальных слов (если слово повторяется больше 1 раза, то вывести его надо один раз). 
	Продемонстрировать работу функции, передав итераторы различных типов.*/

	std::vector<std::string> v {"one", "two", "two", "three", "three"};
	unique_str(v.begin(), v.end());
	std::multiset<std::string> s{ "one", "two", "two", "three", "three" };
	unique_str(s.begin(), s.end());

	/* 2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные пользователем
	из стандартного потока ввода и разбивать их на предложения. Далее программа должна вывести пользователю все предложения,
	а также количество слов в них, отсортировав предложения по количеству слов.*/

	std::string data;
	std::getline(std::cin, data);
	std::multimap<int,std::string> sentenses;
	auto it = sentenses.begin();
	size_t count = 0;
	std::string str;
	for (auto i : data)
	{
		if (i == ' ' && !str.empty() && str.find('-') != std::string::npos) count++;
		str += i;
		if (i == '.')
		{
			count++;
			sentenses.insert({count, str});
			str.clear();
			count = 0;
		}
	}
	for (auto i : sentenses)
	{
		std::cout << "count: " << i.first << " " << i.second << std::endl;
	}
}