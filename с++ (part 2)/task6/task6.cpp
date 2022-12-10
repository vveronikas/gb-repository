#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

std::mutex m;

void pcout(std::string data)
{
	std::lock_guard<std::mutex> lc(m);
	std::cout << data << " ";
}

void house(std::vector<int>& v)
{
	for (size_t i = 0; i < 20; i++)
	{
		m.lock();
		v.push_back(rand() % 10);
		std::cout << "House added sth : ";
		for (auto& i : v)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
		m.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void robber(std::vector<int>& v)
{
	for (size_t i = 0; i < 40; i++)
	{
		m.lock();
		if (v.size() > 0)
		{
			int max = -1;
			std::vector<int>::iterator maxIt;
			for (auto i = v.begin(); i < v.end(); ++i)
			{
				if (max < *i)
				{
					max = *i;
					maxIt = i;
				}
			}
			if (max != -1) v.erase(maxIt);
			std::cout << "Robeer removed : " << max;
			std::cout << std::endl;
			m.unlock();
		}
		else
		{
			std::cout << "House is empty..." << std::endl;
			m.unlock();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

bool is_prime(int n)
{
	int count = 0;

	for (int i = n - 1; i > 1; i--) 
	{
		if (n % i == 0) 
			count++;
	}

	if (count == 0)
		return true;
	else
		return false;
}

void prime_number(int n, bool& is_completed)
{
	int i = 0;
	int number = 0;
	while (i != n)
	{
		number++;
		if (is_prime(number) == true)
			i++;
	}
	std::cout << i << " prime number is " << number;
	is_completed = true;
}

void calculations(bool& is_completed)
{
	while (!is_completed)
	{
		std::cout << "calculation in progress..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

int main()
{
	/* 1. Создайте потокобезопасную оболочку для объекта cout.Назовите ее pcout.Необходимо,
		чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль.
		Продемонстрируйте работу pcout.*/

	std::thread t1(pcout, "Hello");
	std::thread t2(pcout, "World");
	t1.join();
	t2.join();	

	/* 3. Промоделировать следующую ситуацию. Есть два человека(2 потока) : хозяин и вор. Хозяин приносит
		домой вещи(функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду).
		При этом у каждой вещи есть своя ценность.Вор забирает вещи(функция, которая находит наибольшее 
		число и удаляет из вектора с периодичностью 1 раз в 0.5	секунд), каждый раз забирает вещь с
		наибольшей ценностью.*/

	std::vector<int> v {1, 3, 6, 2, 8, 4};
	std::thread t3(house, std::ref(v));
	std::thread t4(robber, std::ref(v));
	t3.join();
	t4.join();

	/* 2. Реализовать функцию, возвращающую i - ое простое число(например, миллионное простое
	число равно 15485863).Вычисления реализовать во вторичном потоке.В консоли отображать
	прогресс вычисления(в основном потоке). */

	bool is_completed = false;
	int n = 10000;
	std::thread t5(prime_number, n, std::ref(is_completed));
	std::thread t6(calculations, std::ref(is_completed));
	t5.join();
	t6.join();
}