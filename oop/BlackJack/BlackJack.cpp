#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "BlackJack.h"

using namespace std;

Card::Card(CardSuit s, CardValue v) { suit = s, value = v, isFace = true; };
Card::~Card() {};
void Card::flip()
{
    if (isFace == true) isFace = false;
    else isFace = true;
}
int Card::getValue()
{
    if (isFace)
    {
        if (value > 10) return 10;
        else return int(value);
    }
    else return 0;
}

ostream& operator<< (ostream& out, const Card c)
{
   const string suits[] = { "d", "h", "c", "s" };
   const string ranks[] = { "NULL", "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", 
                            "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
  
   if (c.isFace) out << "[" << suits[c.suit] << " , " << ranks[c.value] << "] ";
   else out << "[XX] ";
   return out;
}

Hand::Hand() {};
Hand::~Hand() {};
void Hand::add(Card* c) { cards.push_back(c); }
void Hand::clear() { cards.clear(); }
int Hand::getTotal() const
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

GenericPlayer::GenericPlayer(string s) { name = s; };
GenericPlayer::~GenericPlayer() {};
bool GenericPlayer::IsBusted() { return (getTotal() > 21); }
void GenericPlayer::Bust() { cout << name << " is busted" << endl; }

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

Player::Player(string s) : GenericPlayer(s) {};
Player::~Player() {};
bool Player::IsHitting()
{
    char ch;
    do
    {
        cout << name << ", do you need another card? Total value now: " << getTotal() << " (y / n) : ";
        cin >> setw(1) >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (ch != 'y' && ch != 'n');

    if (ch == 'y') return true;
    else if (ch == 'n') return false;
}
void Player::Win() const { cout << name << " won!" << endl; }
void Player::Lose() const { cout << name << " lost :(" << endl; }
void Player::Push() const { cout << name << ", it is draw." << endl; }

House::House() : GenericPlayer("House") {};
House::~House() {};
bool House::IsHitting() {return (getTotal() <= 16); }
void House::FlipFirstCard()
{
    auto it = cards.begin();
    (*it)->flip();
}

Deck::Deck() { populate(); }
Deck::~Deck() {};
void Deck::populate()
{
    for (size_t i = DIAMONDS; i <= SPADERS; i++)
    {
        for (size_t j = ACE; j < KING; j++)
        {
            add(new Card(static_cast<CardSuit>(i), static_cast<CardValue>(j)));
        }
    }
}
void Deck::shuffle() { random_shuffle(cards.begin(), cards.end()); };
void Deck::deal(Hand& h)
{
    if (cards.empty())
    {
        cout << "There are no any cards!" << endl;
    }
    else
    {
        h.add(cards.back());
        cards.pop_back();
    }
};
void Deck::additionalCards(GenericPlayer& p)
{
    while (p.IsHitting() && !p.IsBusted())
    {
        deal(p);
        cout << p;
        if (p.IsBusted())
            p.Bust();
    }
};

Game::Game(const vector<string>& names)
{
    vector<string>::const_iterator it;
    for (it = names.begin(); it < names.end(); it++)
    {
        players.push_back(Player(*it));
    }
    deck.populate();
    deck.shuffle();
}
Game::~Game() {};

void Game::play()
{
    for (size_t i = 0; i < 2; i++)
    {
        for (auto i = players.begin(); i < players.end(); i++)
        {
            deck.deal(*i);
        }
        deck.deal(house);
    }

    house.FlipFirstCard();

    for (auto i = players.begin(); i < players.end(); i++)
    {
        cout << *i;
    }
    cout << house;

    for (auto i = players.begin(); i < players.end(); i++)
    {
        deck.additionalCards(*i);
    }

    house.FlipFirstCard();
    deck.additionalCards(house);

    if (house.IsBusted())
    {
        for (auto i = players.begin(); i < players.end(); i++)
        {
            if (!(*i).IsBusted())
            {
                (*i).Win();
            }
            else
            {
                (*i).Lose();
            }
        }
    }
    else
    {
        for (auto i = players.begin(); i < players.end(); i++)
        {
            if (!(*i).IsBusted())
            {
                if ((*i).getTotal() > house.getTotal())
                {
                    (*i).Win();
                }
                else if ((*i).getTotal() < house.getTotal())
                {
                    (*i).Lose();
                }
                else
                {
                    (*i).Push();
                }
            }
            else
            {
                (*i).Lose();
            }
        }
    }

    for (auto i = players.begin(); i < players.end(); i++)
    {
        (*i).clear();
    }
    house.clear();
}