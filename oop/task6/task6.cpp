// task6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int getInt()
{
    int n;
    while (true)
    {
        cout << "Enter an int number: ";
        cin >> n;
        if (std::cin.fail())
        {
            cerr << "Incorrect input! Try again" << endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else return n;
    }
}

ostream& endll(ostream& out)
{
    out.flush();
    out << "\n" << "\n";
    return out;
}

int main()
{
    /*Создать программу, которая считывает целое число типа int. И поставить «защиту от дурака»: 
    если пользователь вводит что-то кроме одного целочисленного значения, 
    нужно вывести сообщение об ошибке и предложить ввести число еще раз. 
    Пример неправильных введенных строк:
        rbtrb
        nj34njkn
        1n */

    int n = getInt();
    
    /*Создать собственный манипулятор endll для стандартного потока вывода, который выводит два перевода строки и сбрасывает буфер.*/

    cout << n << endll;
}

