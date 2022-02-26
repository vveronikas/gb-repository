#include <iostream>
#include <vector>
#include <iomanip>
#include "BlackJack.h"

using namespace std;
int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "Enter a players count: ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter a player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game g(names);
    char again = 'y';
    do
    {
        g.play();
        cout << "Do you want to play again? (y/n): ";
        cin >> setw(1) >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (again == 'y' || again == 'Y');
}