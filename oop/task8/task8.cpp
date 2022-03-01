#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
T div(T a, T b)
{
    if (b == 0) throw "Can't divide by zero";
    else return a / b;
}

class Ex
{
public:
    Ex(double a) : x(a) {};
    ~Ex() {};
    double getX() { return x; };
private:
    double x;
};

class Bar
{
public:
    Bar() : y(0) {};
    ~Bar() {};
    void set(double a)
    {
        if (y + a > 100) throw Ex(y * a);
        else y = a;
    };
private:
    double y;
};

class OffTheField
{
public:
    OffTheField(int pX, int pY, int mX, int mY)
    {
        positionX = pX;
        positionY = pY;
        moveX = mX;
        moveY = mY;
    };

    friend ostream& operator<< (ostream& out, const OffTheField& n);
protected:
    int positionX;
    int positionY;
    int moveX;
    int moveY;
};

ostream& operator<< (ostream& out, const OffTheField& n)
{
    out << "Robot has tried to leave the field! ( x = " << n.moveX << " y = " << n.moveY << " )" << endl;
    out << "Current position x = " << n.positionX << " y = " << n.positionY << endl;
    return out;
}

class IllegalCommand
{
public:
    IllegalCommand(int pX, int pY, int mX, int mY)
    {
        positionX = pX;
        positionY = pY;
        moveX = mX;
        moveY = mY;
    };
    friend ostream& operator<< (ostream& out, const IllegalCommand& n);
protected:
    int positionX;
    int positionY;
    int moveX;
    int moveY;
};

ostream& operator<< (ostream& out, const IllegalCommand& n)
{
    out << "Illegal command! ( x = " << n.moveX << " y = " << n.moveY << " ) Robot can move only to adjacent cell" << endl;
    out << "Current position x = " << n.positionX << " y = " << n.positionY << endl;
    return out;
}


class Robot
{
public:
    Robot() : x(0), y(0) {};
    void move(int _x, int _y)
    {
        if (abs(x - _x) > 1 || abs(y - _y) > 1)  throw IllegalCommand(x, y, _x, _y); 
        else if (_x < 0 || _x > 9 || _y < 0 || _y > 9) throw OffTheField(x, y, _x, _y);
        else
        {
            x = _x;
            y = _y;
            cout << "Robot has moved to x = " << x << " y = " << y << endl;
        }
    }
private:
    int x;
    int y;
};

int main()
{
    /*1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero, 
    если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения.*/

    double a = 1.4, b = 0;

    try
    {
        cout << a << " / " << b << " = " << div(a, b) << endl; 
    }
    catch (const char* ex)
    {
        cerr << ex << endl;
    }

    /*2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу,
    инициализирующий x значением параметра. Написать класс Bar, хранящий вещественное число y 
    (конструктор по умолчанию инициализирует его нулем) и имеющий метод set с единственным вещественным параметром a.
    Если y + a > 100, возбуждается исключение типа Ex с данными a*y, иначе в y заносится значение a.
    В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
    Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0. 
    В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.*/

    Bar bar;
    int n;
    do
    {
        try
        {
            cout << "Enter a number (for exit 0): ";
            cin >> n;
            bar.set(n);
        }
        catch (Ex& ex)
        {
            cerr << "Error: " << ex.getX() << endl;
        }
    } while (n != 0);

    /*3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, 
    у которого есть метод, означающий задание переместиться на соседнюю позицию. 
    Эти методы должны запускать классы-исключения OffTheField, если робот должен уйти с сетки, 
    и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
    Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
    Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,
    а также выводящую подробную информацию о всех возникающих ошибках.*/

    Robot r;
    int x, y;
    char again;
    do
    {
        cout  << endl << "Enter x and y to move the robot : ";
        cin >> x >> y;
        if (std::cin.fail())
        {
            cerr << "Incorrect input! Try again" << endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
        else
        {
            try
            {
                r.move(x, y);
            }
            catch (OffTheField& ex)
            {
                cerr << ex;
            }
            catch (IllegalCommand& ex)
            {
                cerr << ex;
            }
        }
        cout << "Again? (y/n): ";
        cin >> setw(1) >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (again != 'n');
   
}