#include <iostream>

#ifndef ARRAYINT_H
#define ARRAYINT_H

#include <cassert> 
#include <vector>
#include <algorithm>

class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        m_length++;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    void push_front(int value) { insertBefore(value, 0); }

    void pop_back()  { resize(m_length - 1); }

    void pop_front()
    {
        if (m_length - 1 <= 0)
        {
            erase();
            return;
        }
        else
        {
            int* data = new int[m_length - 1];

            for (size_t i = 1; i < m_length; i++)
            {
                data[i-1] = m_data[i];
            }
             
            delete m_data;

            m_data = data;
            m_length--;
        }
    }

    void sortArr()
    {
        for (size_t i = 0; i < m_length; i++)
        {
            for (size_t j = i + 1; j < m_length; j++)
            {
                if (m_data[i] > m_data[j])
                {
                    std::swap(m_data[j], m_data[i]);
                }

            }
        }  
    }

    void print()
    {
        if (m_length > 0)
        {
            for (size_t i = 0; i < m_length; i++)
            {
                std::cout << m_data[i] << " ";
            }
            std::cout << std::endl;
        }
        else
            std::cout << "Array is empty!" << std::endl;
    }
};

#endif

enum CardSuit
{
    DIAMONDS,  // бубы
    HEARTS,    // черви
    CLUBS,     // трефы
    SPADERS    // пики
};

enum CardValue
{
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    QUEEN = 10,
    KING = 10,
    ACE = 1
};

class Card
{
private:
    CardSuit suit;
    CardValue value;
    bool isFace;
public:
    Card(CardSuit s, CardValue v) { suit = s, value = v, isFace = false; };

    void flip()
    {
        if (isFace == true) isFace = false;
        else isFace = true;
    }
    int getValue()
    { 
        if (value == ACE)
        {
            std::cout << "It is Ace. Do you want 1 or 11?";
            int v;
            std::cin >> v;
            return v;
        }
        return int(value); }
};

class Hand
{
private:
    std::vector<Card*> cards;
public:
    void add(Card* c) { cards.push_back(c); }
    void clear() { cards.clear(); }
    int getValue()
    {
        int sum = 0;
        for (auto  i = cards.begin(); i < cards.end(); i++)
        {
            sum += (**i).getValue();
        }
        return sum;
    }
};


int main()
{
    /*Добавить в контейнерный класс, который был написан в этом уроке, методы:
        для удаления последнего элемента массива (аналог функции pop_back() в векторах)
        для удаления первого элемента массива (аналог pop_front() в векторах)
        для сортировки массива
        для вывода на экран элементов.*/

    ArrayInt arr;
    arr.push_front(2);
    arr.push_front(3);
    arr.push_front(1);

    arr.sortArr();
    arr.print();

    arr.pop_back();
    arr.print();
    arr.pop_front();
    arr.print();
   
    /*Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться использовать максимально быстрый алгоритм.*/
    std::vector<int> v ={ 3, 1, 6, 7, 2, 9, 7, 7, 2 };
    std::sort(v.begin(), v.end());
    int count = 0;
    int tmp;
    for (auto i = v.begin(); i < --v.end(); i++)
    {
        auto it = i;
        tmp = *(++it);
       
        if (tmp != *i)
            count++;
    }
    std::cout << count << std::endl;

    /*Реализовать класс Hand, который представляет собой коллекцию карт. В классе будет одно поле: 
         вектор указателей карт (удобно использовать вектор, т.к. это по сути динамический массив, 
         а тип его элементов должен быть - указатель на объекты класса Card). 
     Также в классе Hand должно быть 3 метода:
        метод Add, который добавляет в коллекцию карт новую карту, соответственно он принимает в качестве параметра указатель на новую карту
        метод Clear, который очищает руку от карт
        метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть возможность того, что туз может быть равен 11).*/
    Card c1(DIAMONDS, JACK);
    Card c2(DIAMONDS, TWO);
    Card c3(DIAMONDS, ACE);

    Hand h;
    h.add(&c1);
    h.add(&c2);
    h.add(&c3);

    std::cout << "Sum of the cards = "  << h.getValue() << std::endl;

    h.clear();
}