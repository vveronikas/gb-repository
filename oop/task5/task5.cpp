#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Pair1
{
private:
    T a;
    T b;
public:
    Pair1(T aa, T bb) { a = aa; b = bb; }
    T first() const { return a; };
    T second() const { return b; };
};

template <typename T1, typename T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    Pair(T1 aa, T2 bb) { a = aa; b = bb; }
    auto first() const { return a; };
    auto second() const { return b; };
};

template <typename T>
class StringValuePair : public Pair<string, T>
{
private:
    string a;
    T b;
public:
    StringValuePair(string aa, T bb) : Pair<string, T>(aa, bb) { a = aa, b = bb; };
};

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
            cout << "It is Ace. Do you want 1 or 11?";
            int v;
            cin >> v;
            return v;
        }
        return int(value);
    }
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
        for (auto i = cards.begin(); i < cards.end(); i++)
        {
            sum += (**i).getValue();
        }
        return sum;
    }
};

class GenericPlayer : public Hand
{
private:
    string name;
public:
   GenericPlayer(string s) { name = s; }
   virtual bool IsHitting() = 0;
   bool IsBusted() 
   {
       if (getValue() > 21) return true;
       else return false;
   };
   void Bust()  { cout << name << " is busted" << endl; }
};

int main()
{
    /*Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.*/
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    /*Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.*/
    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    /*Написать шаблон класса StringValuePair, в котором первое значение всегда типа string,
    а второе — любого типа. Этот шаблон класса должен наследовать частично специализированный класс Pair,
    в котором первый параметр — string, а второй — любого типа данных.*/

    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    /*Согласно иерархии классов, которая представлена в методичке к уроку 3, от класса Hand наследует класс GenericPlayer, 
    который обобщенно представляет игрока, ведь у нас будет два типа игроков - человек и компьютер. 
    Создать класс GenericPlayer, в который добавить поле name - имя игрока. Также добавить 3 метода:
        IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли игроку еще одна карта.
        IsBusted() - возвращает bool значение, есть ли у игрока перебор
        Bust() - выводит на экран имя игрока и объявляет, что у него перебор.*/

   // Card c1(DIAMONDS, JACK);
   // Card c2(DIAMONDS, TWO);
   // Card c3(DIAMONDS, ACE);

   //  GenericPlayer h("Veronika");
   //  h.add(&c1);
   //  h.add(&c2);
   //  h.add(&c3);

   // if (h.IsBusted()) h.Bust();





}
