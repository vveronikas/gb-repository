#include <iostream>
 
void initArr(int** arr, const int sizeX, const int sizeY)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        arr[y] = new int[sizeX];
        for (size_t x = 0; x < sizeX; x++)
        {
            arr[y][x] = rand() % 10;
        }
    }
}

void printArr(int ** arr, const int sizeX, const int sizeY)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
        {
           std::cout << arr[y][x] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void deleteArr(int** arr, const int sizeX, const int sizeY)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        delete[] arr[y];
    }
    delete[] arr;
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int** arr, int sizeX, int sizeY)
{
    for (size_t y = 0; y < sizeY; y++)
    {
        for (size_t x = 0; x < sizeX; x++)
        {
            for (size_t i = 0; i < sizeY; i++)
            {
                for (size_t j = 0; j < sizeX; j++)
                {
                    if (arr[y][x] < arr[i][j])
                        swap(&arr[y][x], &arr[i][j]);
                }
            }
        }
    }

}

void algoTrabb()
{
    // enter
    std::cout << "Enter 11 numbers";
    int arr[11];
    for (size_t i = 0; i < 11; i++)
    {
        std::cin >> arr[i];
    }

    //invert
    for (size_t i = 0; i < 6; i++)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[10 - i];
        arr[10 - i] = temp;       
    }
    
    //print
    for (size_t i = 0; i < 11; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    //calculations
    for (size_t i = 0; i < 11; i++)
    {
        if (sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3) > 400)
        {
            std::cout << "the result of calculations for " << arr[i] << " is greater then 400" << std::endl;
        }
    }  
}

int main()
{
    // Реализовать пузырьковую сортировку двумерного массива
    const int SIZE_Y = 5;
    const int SIZE_X = 3;
    int** arr = new int *[SIZE_Y];
    initArr(arr, SIZE_X, SIZE_Y);
    printArr(arr, SIZE_X, SIZE_Y);
    bubbleSort(arr, SIZE_X, SIZE_Y);
    printArr(arr, SIZE_X, SIZE_Y);
    deleteArr(arr, SIZE_X, SIZE_Y);

    //Реализовать алгоритм Трабба-Прадо-Кнута
    algoTrabb();
}

