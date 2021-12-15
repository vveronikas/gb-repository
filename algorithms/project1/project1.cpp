
// Написать функцию проверки, является ли число простым
#include <iostream>

void isPrime( int n ) {

    int count = 0;

    for (int i = n - 1; i > 1; i--) {

        if (n % i == 0) {

            count++;
            break;
        }
    }

    if (count == 0) {

        std::cout << n << " is a prime number" << std::endl;
    }
    else {

        std::cout << n << " is NOT a prime number" << std::endl;
    }
}

int main()
{
    int n;
    std::cout << "Enter a number" << std::endl;
    std::cin >> n;
    isPrime(n);
}
