// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdint>

class Power {
private:
    double num = 1.5;
    double numPower = 2.1;

public:
    void set(double _num, double _numPower)
    {
        num = _num;
        numPower = _numPower;
    };
    void calculate()
    {    
        std::cout << "result = " << pow(num, numPower) << std::endl;
    };
};

class RGBA {
private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
public:
    RGBA(uint8_t _red, uint8_t _green, uint8_t _blue, uint8_t _alpha)
    {
        m_red = _red;
        m_green = _green;
        m_blue = _blue;
        m_alpha = _alpha;
    };

    void print()
    {
        std::cout << "m_red = " << m_red << std::endl;
        std::cout << "m_green = " << m_green << std::endl;
        std::cout << "m_blue = " << m_blue << std::endl;
        std::cout << "m_alpha = " << m_alpha << std::endl;
    };
};

class Stack {
private:
    int arr[10];
    int len;

public:
    void reset()
    {
        for (size_t i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
        len = 0;
    };

    bool push(int data)
    {
        if (len == 10)
            return false;
        else
        {
            arr[len] = data;
            len++;
            return true;
        }
    };

    int pop()
    {
        if (len == 0)
        {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        else
        {
            len--;
            int tmp = arr[len];
            arr[len] = 0;
            return tmp;
        }
    };

    void print()
    {
        std::cout << "( ";
        for (size_t i = 0; i < 10; i++)
        {
            if (arr[i] != 0)
                std::cout << arr[i];
            else
                break;
        }
        std::cout << " )" << std::endl;
    };
};

int main()
{
    /*Создать класс Power, который содержит два вещественных числа. 
    Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
    Еще создать два метода: один с именем set, который позволит присваивать значения переменным,
    второй — calculate, который будет выводить результат возведения первого числа в степень второго числа.
    Задать значения этих двух чисел по умолчанию.*/

    Power p;
    p.calculate();
    p.set(2, 3);
    p.calculate();

    /*Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
    std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).
    Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
    Создать конструктор со списком инициализации членов, 
    который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. 
    Написать функцию print(), которая будет выводить значения переменных-членов.*/

    RGBA colors(1,2,3,4);
    colors.print();

    /*Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
        private-массив целых чисел длиной 10;
        private целочисленное значение для отслеживания длины стека;
        public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
        public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, 
            если массив уже заполнен, и true в противном случае;
        public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений,    то должно выводиться предупреждение;
        public-метод с именем print(), который будет выводить все значения стека.*/

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}