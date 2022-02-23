// BlackJack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

enum CardSuit
{
    DIAMONDS,  // бубы
    HEARTS,    // черви
    CLUBS,     // трефы
    SPADERS    // пики
};

enum CardValue
{
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING
};

class Card
{
protected:
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
        if (isFace)
        {
            if (value > 10) return 10;
            else return int(value);
        }
        else return 0;
        
    }

    friend ostream& operator<< (ostream& out, const Card c);
};

ostream& operator<< (ostream& out, const Card c)
{

   const string suits[] = { "d", "h", "c", "s" };
   const string ranks[] = { "NULL", "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", 
                            "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
  
    if (c.isFace) out << "[" << suits[c.suit] << " , " << ranks[c.value] << "] ";
    else out << "[XX] ";
    return out;
}

class Hand
{
protected:
    std::vector<Card*> cards;
public:
    void add(Card* c) { cards.push_back(c); }
    void clear() { cards.clear(); }
    int getTotal () const
    {
        if (cards.empty())
        {
            return 0;
        }

        int sum = 0;
        for (auto i = cards.begin(); i < cards.end(); i++)
        {
            if ((**i).getValue() == ACE && sum < 11) sum += 11;  
            else sum += (**i).getValue();
        }
        return sum;
    }
};

class GenericPlayer : public Hand
{
protected:
    string name;
public:
    GenericPlayer(string s) { name = s; }
    virtual bool IsHitting() = 0;
    bool IsBusted() {return (getTotal() > 21); }
    void Bust() { cout << name << " is busted" << endl; }

    friend ostream& operator<< (ostream& out, const GenericPlayer &p);
};

ostream& operator<< (ostream& out, const GenericPlayer &p)
{
    out << "Player: " << p.name << endl;
    for (auto i = p.cards.begin(); i < p.cards.end(); i++)
    {
        out << (**i);
    }
    out << endl;
    out << "Total value: " << p.getTotal() << endl << endl;
    
    return out;
}

class Player : public GenericPlayer
{
public:
    Player(string s) : GenericPlayer(s) {};
    virtual bool IsHitting() override 
    {
        char ch;
        do 
        {
            cout << "Do you need another one card? (y/n): ";
            cin >> setw(1) >> ch;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } while (ch != 'y' && ch != 'n');

        if (ch == 'y') return true;
        else if (ch == 'n') return false;
    }
    void Win() const { cout << name << " won!" << endl; }
    void Lose() const { cout << name << " lost :(" << endl; }
    void Push() const { cout << name << ", it is draw." << endl; }
};

class House : public GenericPlayer
{
public:
    House() : GenericPlayer("House") {};
    virtual bool IsHitting() override {return (getTotal() <= 16); }
    void FlipFirstCard()
    {
        auto it = cards.begin();
        (*it)->flip();
    }
};

int main()
{

    /*3. Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса будет 4 метода:
        virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. 
        Метод спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false. 
        void Win() const - выводит на экран имя игрока и сообщение, что он выиграл.
        void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
        void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.*/

        Card c1(DIAMONDS, JACK);
        Card c2(DIAMONDS, TWO);
        Card c3(DIAMONDS, ACE);

        Player p1("Veronika");
        p1.add(&c1);
        p1.add(&c2);
        p1.add(&c3);

        p1.IsHitting();

    /*4. Реализовать класс House, который представляет дилера. Этот класс наследует от класса GenericPlayer. У него есть 2 метода:
        virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
        void FlipFirstCard() - метод переворачивает первую карту дилера.*/

        House h;
        Card c4(HEARTS, KING);
        Card c5(HEARTS, QUEEN);
        h.add(&c4);
        h.add(&c5);
        h.FlipFirstCard();

    /*5. Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой вверх (мы ее не видим),
    вывести ХХ, если мы ее видим, вывести масть и номинал карты. 
    Также для класса GenericPlayer написать перегрузку оператора вывода, который должен отображать имя игрока и его карты,
    а также общую сумму очков его карт.*/

        c1.flip();
        c2.flip();
        c3.flip();

        cout << p1;
        cout << h;
       






    
}