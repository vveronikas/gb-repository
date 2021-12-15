
#include <iostream>

void decToBin(int n)
{
	 if  (n > 1)
		 decToBin(n / 2);

	 std::cout << n % 2;
}

int numInPower(int a, int b, int res = 1)
{
	if (b == 0)
		return res;
	else numInPower(a, b - 1, res * a);
}

const int SIZE = 4;

int field[SIZE][SIZE] = { {0, 0, 1, 0},
						  {1, 0, 0, 0},
						  {0, 1, 0, 0}, 
						  {0, 0, 0, 0} };

int routs(int i, int j)
{
	if (field[i][j] == 1)
	return 0;

	else if (i == 0 && j == 0)
		return 0;

	else if (((i == 0) && (j == 1) || (j == 0) && (i == 1)))
		return 1;

	if (i == 0)
	{
		if (routs(i, j - 1) == 0 && j != 1)
			return 0;
		else
			return 1;
	
	}
	else if (j == 0)
	{
		if (routs(i - 1, j) == 0 && i != 1)
			return 0;
		else
			return 1;
	}

	else
		return routs(i - 1, j) + routs(i, j - 1);
}

int main()
{
	// Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию
	int n;
	std::cout << "Enter a nuber" << std::endl;
	std::cin >> n;
	decToBin(n);
	std::cout << std::endl;

	//Реализовать функцию возведения числа[a] в степень[b]:
	//Рекурсивно.
	
	int a, b;
	std::cout << "Enter a nuber and a power" << std::endl;
	std::cin >> a >> b;

	std::cout << numInPower(a, b) << std::endl;

	//Рекурсивно, используя свойство чётности степени(то есть, если степень, в которую нужно возвести число,
	//чётная, основание возводится в квадрат, а показатель делится на два, а если степень нечётная
	//- результат умножается на основание, а показатель уменьшается на единицу)

	if (b % 2 == 0)
		std::cout << numInPower(a * a, b / 2) << std::endl;
	else
		std::cout << a * numInPower(a, b - 1) << std::endl;

	//Реализовать нахождение количества маршрутов шахматного короля с препятствиями
	//(где единица - это наличие препятствия, а ноль - свободная для хода клетка)

	std::cout << "Field: " << std::endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			std::cout << field[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "Number of routes: " << std::endl;

	for (size_t i = 0; i < SIZE; i++)
	{
		for (size_t j = 0; j < SIZE; j++)
		{
			std::cout << routs(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

