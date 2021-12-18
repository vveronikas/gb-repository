#include <iostream>

void initArr(int* arr, const int len)
{
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = rand() % 10;
	}
}

void printArr(int *arr, const int len)
{
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void insertSort(int *arr, int len)
{
    int temp, itemp; //индекс предыдущего элемента
	for (size_t i = 1; i < len; i++)
	{
		temp = arr[i]; // сортируемый элемент
		itemp = i - 1; //индекс пердыдущего элемента
		while (itemp >= 0 && arr[itemp] > temp) // пока индекс не 0 и пред. эл. больше текущего
		{
			arr[itemp + 1] = arr[itemp]; //перестановка 
			arr[itemp] = temp;
			itemp--;
		}
	}
}

int mediana(int * arr, int a, int b, int c)
{
	int *arrSort = new int[3];
	arrSort[0] = arr[a];
	arrSort[1] = arr[b];
	arrSort[2] = arr[c];
	insertSort(arrSort, 3);

	int temp;
	if (arrSort[1] == arr[a])
		temp = a;
	if (arrSort[1] == arr[b])
		temp = b;
	if (arrSort[1] == arr[c])
		temp = c;

	delete[] arrSort;
	return temp;
}

void swap(int *a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void improveQS(int* arr, int first, int last)
{
	if (last - first + 1 <= 10)
		insertSort(arr, last - first + 1);
	else
	{
		int med;
		med = mediana(arr, first, (last - first) / 2, last);
		swap(&arr[med], &arr[(last - first) / 2]);

		int i = first;
		int j = last;
		int x = arr[(last - first) / 2];

		do {
			while (arr[i] < x) i++; //ищем индек элемента который больше 
			while (arr[j] > x) j--; //и меньше опроного

			if (i <= j)
			{
				swap(&arr[i], &arr[j]); //меняем местами найденные элементы
			    i++;
				j--;
			}
		} while (i <= j);

		if (i < last) improveQS(arr, i, last);
		if (first < j) improveQS(arr, first, j);
	}
}

void sortEvenNum(int* arr, int len)
{	
	const int max = len;
	const int b = 10;

	int** buckets = new int* [b];
	for (size_t i = 0; i < b; i++)
	{
		buckets[i] = new int[max+1];
		buckets[i][max] = 0;
	}

	for (size_t dight = 1; dight < 1000; dight = dight * 10)
	{
		for (size_t i = 0; i < max; i++)
		{
			if (arr[i] % 2 == 0 && (arr[i] / dight > 0 || arr[i] == 0)) {
				int d = (arr[i] / dight) % b;
				int counter = buckets[d][max];
				buckets[d][counter] = arr[i];
				counter++;
				buckets[d][max] = counter;
			}
		}
	}

	int y = 0; // from 0 to b
	int x = 0; //from 0  to  buckets[y][max]
	for (size_t i = 0; i < max; i++)
	{
		if (arr[i] % 2 == 0) {
			while (buckets[y][max] == 0)
			{
				y++;
			}
			arr[i] = buckets[y][x];
			
			if (x < buckets[y][max] - 1)
				x++;
			else {
				buckets[y][max] = 0;
				y++;
				x = 0;
			}
		}
	}

	for (size_t i = 0; i < b; i++)
	{
		delete[] buckets[i]; 
	}
	delete[] buckets;
}

int main()
{
   //улучшенная быстрая сортировка
	std::cout << " improve quick sort: " << std::endl;
	const int SIZE = 20;
	int* arr = new int[SIZE];
	initArr(arr, SIZE);
	printArr(arr, SIZE);
	improveQS(arr, 0, SIZE-1);
	printArr(arr, SIZE);
	delete[] arr;

	// Сортировать в массиве целых положительных чисел только чётные числа,
	//нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
	//то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 6 5 9 8 8 7 3]

	std::cout << " sort only even numbers: " << std::endl;
	int* arrEven = new int[SIZE];
	initArr(arrEven, SIZE);
	printArr(arrEven, SIZE);
	sortEvenNum(arrEven, SIZE);
	printArr(arrEven, SIZE);
	delete[] arrEven;
}

