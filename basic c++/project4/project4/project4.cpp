
#include <iostream>

void coutArr(double* arr, int n) {

    for (int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void coutArr(int* arr, int n) {

    for (int i = 0; i < n; i++) {

        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

 void changeZeroToOne(int* arr, int n) {

     for (int i = 0; i < n; i++) {

         if (arr[i] == 0) {
             arr[i] = 1;
         }
         else if (arr[i] == 1) {
             arr[i] = 0;
         }
     }
}

 void initArr(int* arr, int n) {

     int count = 1;

     for (int i = 0; i < n; i++) {

         arr[i] = count;
         count += 3;
     }

 }

 void shiftArr(int* arr, int* newArr, int sizeArr, int shiftSize) {


     if (shiftSize > sizeArr) {
         shiftSize = shiftSize - sizeArr * (shiftSize / sizeArr);
     }

     for (int i = 0; i < sizeArr; i++) {

         int newSpot = i + shiftSize;
         
         while (newSpot > sizeArr - 1) {

             newSpot = i + shiftSize;

             if (i + shiftSize > sizeArr - 1) {
                 newSpot = i + shiftSize - sizeArr;
             }

         }

         newArr[newSpot] = arr[i];
     }
 }

 bool chekBalance(int* arr, int size) {

     bool balance = false;

     for (int i = 0; i < size; i++) {

         int rightSum = 0, leftSum = 0;

         for (int j = 0; j <= i; j++) {
             
             rightSum += arr[j];
         }

         for (int k = i + 1; k < size; k++) {

             leftSum += arr[k];
         }

         if (rightSum == leftSum) {
             balance = true;
             break;
         }
     }

     return balance;
 }

int main()
{
    // TASK 1
    std::cout << "Task1: ";
    int const SIZE4 = 4;
    double arr[SIZE4] = { 1.34, 3.456, 5.666, 7.993445 };
    coutArr(arr, SIZE4);

    // TASK 2
    std::cout << "Task2: ";
    int const SIZE5 = 5;
    int arr2[SIZE5] = { 0, 1, 0, 0, 1};
    std::cout << "  before: ";
    coutArr(arr2, SIZE5);
    changeZeroToOne(arr2, SIZE5);
    std::cout << "          after: ";
    coutArr(arr2, SIZE5);

    // TASK 3
    std::cout << "Task3: ";
    int const SIZE8 = 8;
    int arr3[SIZE8];
    initArr(arr3, SIZE8);
    coutArr(arr3, SIZE8);

    // TASK 4
    std::cout << "Task4: Please enter a shift number ";
    int shift;
    std::cin >> shift;
 
    int const SIZE6 = 6;
    int arr4[SIZE6] = { 0, 1, 2, 3, 4, 5 };
    int newArr[SIZE6] = { 0 };

    std::cout << "        before: ";
    coutArr(arr4, SIZE6);

    shiftArr(arr4, newArr, SIZE6, shift);
    std::cout << "         after: ";
    coutArr(newArr, SIZE6);

    //TASK 5
    std::cout << "Task5: ";
    int arr5[SIZE5] = { 5, 10, 5, 11, 10};
    std::cout << " arr: ";
    coutArr(arr5, SIZE5);
    std::cout << "        balance is " << std::boolalpha << chekBalance(arr5, SIZE5) << std::endl;;
 }