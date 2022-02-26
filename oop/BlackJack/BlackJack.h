#pragma once

#include <iostream>
#include <vector>

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
    Card(CardSuit s, CardValue v);
    ~Card();

    void flip();
    int getValue();
    friend ostream& operator<< (ostream& out, const Card c);
};

class Hand
{
protected:
    std::vector<Card*> cards;
public:
    Hand();
    ~Hand();
    void add(Card* c);
    void clear();
    int getTotal() const;
};

class GenericPlayer : public Hand
{
protected:
    string name;
public:
    GenericPlayer(string s);
    ~GenericPlayer();
    virtual bool IsHitting() = 0;
    bool IsBusted();
    void Bust();
    friend ostream& operator<< (ostream& out, const GenericPlayer& p);
};

class Player : public GenericPlayer
{
public:
    Player(string s);
    ~Player();
    virtual bool IsHitting() override;
    void Win() const;
    void Lose() const;
    void Push() const;
};

class House : public GenericPlayer
{
public:
    House();
    ~House();
    virtual bool IsHitting() override;
    void FlipFirstCard();
};

class Deck : public Hand
{
public:
    Deck();
    ~Deck();
    void populate();
    void shuffle();

    void deal(Hand& h);
    void additionalCards(GenericPlayer& p);
};

class Game
{
private:
    Deck deck;
    House house;
    vector<Player> players;
public:
    Game(const vector<string>& names);
    ~Game();
    void play();
};
