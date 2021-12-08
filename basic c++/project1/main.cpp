#include <iostream>

enum cells {
    ZERO = '_' ,     
    CROSS  = 'x',    
    EMPTY = '0'
};
enum result{
    wonPlayer1,
    wonPlayer2,
    draw
};
struct player{
    cells myMove;  // what is playing
    std::string name;
};

struct game {
   cells arr[3][3];
   player player1;
   player player2;
   result outcome;
   bool isGameOver;
};

union MyData{
    int i1;
    float f1;
    char ch1;
};

struct MyVariant{
    MyData n1;
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
};

int main() {

    // task 1
    short int n1 = 123;
    int n2 = 1244;
    long long n3 = 45342234342;
    char s1 = 'q';
    bool b1 = true;
    float n4 = 3.25f;
    double n5 = 1234.78;   

    //task 5

    MyVariant var1;
    var1.n1.ch1 = 'q';
    var1.isChar = 1;
    var1.isFloat = 0;
    var1.isInt = 0;


    if (var1.isChar == 1){
        std::cout << var1.n1.ch1;
    } 
    else if (var1.isFloat == 1){
        std::cout << var1.n1.f1;
    } 
    else if (var1.isInt == 1){
        std::cout << var1.n1.i1;
    } 
    return 0;
}