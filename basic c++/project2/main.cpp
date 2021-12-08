#include <iostream>

extern int a, b, c, d;
//int a = 100, b = 30, c = 5, d = 3;

void task4();

void task2() {

    int n;

    std::cout << "Please enter an integer" << std::endl;
    std::cin >> n;
    n = (n <= 21) ? 21 - n : 2 * (n - 21);
    std::cout <<"Result: " << n;

};

void task3() {
    
    int arr[3][3][3] = { {  {1, 2, 3},      {4, 5, 6},    {7, 8, 9} }, 
                            { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} },
                            { {19, 20, 21}, {22, 23, 24}, {25, 26, 27} } };

    int *p = nullptr;
    p = &arr[1][1][1];
    
    std::cout << "arr[1][1][1] = " << *p << std::endl;

};

void task4(){

    std::cout << a * (b + (static_cast<float> (c) / d)) << std::endl;

}

int main() {

    task2();
    task3();
    task4();
    return 0;
}