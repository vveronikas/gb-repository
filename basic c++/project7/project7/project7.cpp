
#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

enum Cell : char
{
    CROSS = 'x',
    ZERO = 'o',
    EMPTY = '_'
};

enum GameProgress 
{
    IN_PROGRESS,
    WON_HUMAN,
    WON_AI,
    DRAW
};

struct Coord 
{
    size_t y{ 0 };
    size_t x{ 0 };
};

struct Game
{
    Cell** ppField = nullptr; // поле
    size_t SIZE;
    Cell human; 
    Cell ai;
    size_t turn = 0; // кто ходит
    GameProgress progress = IN_PROGRESS;
};

void clearScr() 
{
    system("cls");
};

int32_t __fastcall getRandomNum(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
};

void __fastcall initGame(Game& g)
{
    g.ppField = new Cell * [g.SIZE];
    for (size_t y = 0; y < g.SIZE; y++)
    {
        g.ppField[y] = new Cell[g.SIZE];
        for (size_t x = 0; x < g.SIZE; x++)
        {
            g.ppField[y][x] = EMPTY;
        }
    }

    if (getRandomNum(0, 100) > 50)
    {
        g.human = CROSS;
        g.ai = ZERO;
        g.turn = 0;
    }
    else
    {
        g.human = ZERO;
        g.ai = CROSS;
        g.turn = 1;
    }
};
void __fastcall deinitGame(Game& g) 
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;

};

void __fastcall drawGame(const Game& g) 
{
    std::cout << std::endl;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        std::cout << " " << y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
           std::cout << g.ppField[y][x] << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << "  ";
    for (size_t i = 0; i < g.SIZE; i++)
    {
        std::cout << "   " << i + 1;
    }

    std::cout << std::endl << "Human: " << g.human << std::endl;
    std::cout << "AI: " << g.ai << std::endl;

    if (!g.turn) {
        std::cout << "The first turn: Human" << std::endl;
    }
    else
    {
        std::cout << "The first turn: AI" << std::endl;
    }
}

GameProgress __fastcall getWin(Game& g)
{

    //строки
    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[y][0] != EMPTY)
        {
            for (size_t x = 0; x < g.SIZE; x++)
            {
                if (g.ppField[y][x] != g.ppField[y][0]) {
                    break;
                }
                else
                {
                    if (x + 1 == g.SIZE) {
                        if (g.ppField[y][0] == g.human)
                            return WON_HUMAN;
                        if (g.ppField[y][0] == g.ai)
                            return WON_AI;
                    }
                }
            }
        }
    }
    // стоблцы
    for (size_t x = 0; x < g.SIZE; x++)
    {
        if (g.ppField[0][x] != EMPTY)
        {
            for (size_t y = 0; y < g.SIZE; y++)
            {
                if (g.ppField[y][x] != g.ppField[0][x]) {
                    break;
                }
                else
                {
                    if (y + 1 == g.SIZE) {
                        if (g.ppField[0][x] == g.human)
                            return WON_HUMAN;
                        if (g.ppField[0][x] == g.ai)
                            return WON_AI;
                    }
                }
            }
        }
    }
    // диагональ 1
    if (g.ppField[0][0] != EMPTY)
    {
        for (size_t i = 0; i < g.SIZE; i++)
        {
            if (g.ppField[0][0] != g.ppField[i][i]) {
                break;
            }
            else
            {
                if (i + 1 == g.SIZE) {
                    if (g.ppField[0][0] == g.human)
                        return WON_HUMAN;
                    if (g.ppField[0][0] == g.ai)
                        return WON_AI;
                }
            }
        }
    }
    // диагональ 2
    if (g.ppField[0][g.SIZE - 1] != EMPTY)
    {
        for (size_t i = g.SIZE - 1; i >= 0; i--)
        {
            if (g.ppField[0][g.SIZE - 1] != g.ppField[g.SIZE - 1 - i][i]) {
                break;
            }
            else
            {
                if (i == 0) {
                    if (g.ppField[0][g.SIZE - 1] == g.human)
                        return WON_HUMAN;
                    if (g.ppField[0][g.SIZE - 1] == g.ai)
                        return WON_AI;
                }
            }
        }
    }
    // ничья
    bool draw = true;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == EMPTY)
            {
                draw = false;
                break;
            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return DRAW;

    return IN_PROGRESS;
};

bool __fastcall checkAIPreWin(Game& g, Coord c)
{            
    if (g.ppField[c.y][c.x] == EMPTY)
    {
        g.ppField[c.y][c.x] = g.ai;
        if (getWin(g) == WON_AI) {
            g.ppField[c.y][c.x] = EMPTY;
            return true;
        }
        g.ppField[c.y][c.x] = EMPTY;
    }
    return false;

};

bool __fastcall checkAIPreFail(Game& g, Coord c)
{
    if (g.ppField[c.y][c.x] == EMPTY)
    {
        g.ppField[c.y][c.x] = g.human;
        if (getWin(g) == WON_HUMAN) {
            g.ppField[c.y][c.x] = EMPTY;
            return true;
        }
        g.ppField[c.y][c.x] = EMPTY;
    }
    return false;
};

Coord __fastcall getAICoord(Game& g)
{
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (checkAIPreWin(g, { y, x })) {
                return  { y, x };
            }
            else if (checkAIPreFail(g, { y, x })) {
                return  { y, x };
            }

        }
    }

    if ((g.SIZE - 1) % 2 == 0) {
        size_t i = (g.SIZE - 1) / 2;
        if (g.ppField[i][i] == EMPTY)
            return { i,i };
    }

    Coord * c = new Coord[g.SIZE + g.SIZE]; //масив координат для лучших ходов в столбцах и строках
    size_t* count = new size_t[g.SIZE + g.SIZE]; // массив количества заполненных копьютером клеток в столбца и строках 

    // считаем в столбцах
    for (size_t y = 0; y < g.SIZE; y++)
    {
        count[y] = 0;
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[y][x] == g.human)
            {
                count[y] = 0;
                break;
            }

            else if (g.ppField[y][x] == g.ai)
            {
                count[y]++;
                c[y].y = y;
            }
        }   
        if (count[y + g.SIZE] > 0)
            for (size_t x = 0; x < g.SIZE; x++)
            {
                if (g.ppField[y][x] == EMPTY)
                {
                    c[y].x = x;
                    break;
                }
            }
    }

    // считаем в строках
    for (size_t x = 0; x < g.SIZE; x++)
    {
        count[x + g.SIZE] = 0;
        for (size_t y = 0; y < g.SIZE; y++)
        {
            if (g.ppField[y][x] == g.human)
            {
                count[x + g.SIZE] = 0;
                break;
            }

            else if (g.ppField[y][x] == g.ai)
            {
                count[x + g.SIZE]++;
                c[x + g.SIZE].x = x;
            }
        }
        if (count[x + g.SIZE] > 0)
            for (size_t y = 0; y < g.SIZE; y++)
            {
                if (g.ppField[y][x] == EMPTY)
                {
                    c[x + g.SIZE].y = y;
                    break;
                }
            }
    }

    size_t max = 0;
    size_t n = 0;
    for (size_t i = 0; i < g.SIZE + g.SIZE; i++)
    {
        if (max < count[i])
        {
            max = count[i];
            n = i;
        }
            
    }
    size_t x = c[n].x;
    size_t y = c[n].y;
    delete[] c;
    delete[] count;
    
    if (max > 0)
        return { y, x };
   
    Coord arr[4];
    size_t num = 0;
    if (g.ppField[0][0] == EMPTY)
    {
        arr[num++] = { 0,0 };
    }
    if (g.ppField[0][g.SIZE - 1] == EMPTY)
    {
        arr[num++] = { 0,g.SIZE - 1 };
    }
    if (g.ppField[g.SIZE - 1][0] == EMPTY)
    {
        arr[num++] = { g.SIZE - 1, 0 };
    }
    if (g.ppField[g.SIZE - 1][g.SIZE - 1] == EMPTY)
    {
        arr[num++] = { g.SIZE - 1,g.SIZE - 1 };
    }
    if (num > 0)
    {
        const size_t index = getRandomNum(0, 100) % num;
        return arr[index];
    }
    else
    {
        size_t y;
        size_t x;
        do
        {
            y = getRandomNum(0, 100) % (g.SIZE);
            x = getRandomNum(0, 100) % (g.SIZE);
        } while (g.ppField[y][x] != EMPTY);
       
        return { y,x };
    }
};

Coord  _fastcall getHumanCoord(const Game& g)
{
    Coord c;
    do
    {
        std::cout << "Enter y (1.." << g.SIZE << "):";
        std::cin >> c.y;
        std::cout << "Enter x (1.." << g.SIZE << "):";
        std::cin >> c.x;
        c.x--;
        c.y--;
    } while (c.x > 4 || c.y > 4 || g.ppField[c.y][c.x] != EMPTY);

    return c;    
};

void __fastcall congrats(const Game& g)
{
    if (g.progress == WON_AI)
        std::cout << " Computer won! :(" << std::endl;
    if (g.progress == WON_HUMAN)
        std::cout << " Your won! :)" << std::endl;
    if (g.progress == DRAW)
        std::cout << " Draw!" << std::endl;
}



int main()
{
    Game g;
    std::cout << "Enter a field size ";
    std::cin >> g.SIZE;
    initGame(g);
    clearScr();
    drawGame(g);

    do
    {
        if (g.turn % 2 == 0)
        {
            //Human
            Coord c = getHumanCoord(g);
            g.ppField[c.y][c.x] = g.human;
        }
        else
        {
            //Human
            Coord c = getAICoord(g);
            g.ppField[c.y][c.x] = g.ai;
        }

        clearScr();
        drawGame(g);
        g.turn++;
        g.progress = getWin(g); 

    } while (g.progress == IN_PROGRESS);

    congrats(g);

    deinitGame(g);
    return 0;       
}
