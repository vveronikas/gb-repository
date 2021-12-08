#include <iostream>

void task1() {

    int a, b;

    std::cout << "Please enter a and b" << std::endl;
    std::cin >> a >> b;

    if (a + b >= 10 && a + b <= 20) {

        std::cout <<"Task1: true" << std::endl;
    }
    else {

        std::cout << "Task1: false" << std::endl;
    }
}

void task2() {

    int const a  = 5, b = 5;

    if (a == 10 && b == 10 || a + b == 10) {

        std::cout << "Task2: true" << std::endl;
    }
    else {

        std::cout << "Task2: false" << std::endl;
    }
}

void task3() {

    std::cout << "Task3: ";

    for (int i = 1; i <= 50; i++){

        if (i % 2 != 0) { 

            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

void task4() {

    int n, count = 0;

    std::cout << "Please enter a number" << std::endl;
    std::cin >> n;  

    for (int i = n - 1; i > 1; i--){
        
        if (n % i == 0) {

            count++;
        }
    }

    if (count == 0){

        std::cout << "Task4: " << n << " is a prime number" << std::endl; 
    }
    else{

        std::cout << "Task4: " << n << " is NOT a prime number" << std::endl;
    }
}

void task5() {

    int year;

    std::cout << "Please enter a year" << std::endl;
    std::cin >> year;

    std::cout << "Task5: ";

    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){

        std::cout << year << " is a leap year" << std::endl;
    }
    else {

        std::cout << year << " is NOT a leap year" << std::endl;
    }
}

int main() {

    task1();
    task2();
    task3();
    task4();
    task5();
    return 0;

}