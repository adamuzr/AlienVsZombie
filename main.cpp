// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT8L 
// Names: ARMAN HAZIQ BIN ZULKARNAIN | ADAM UZAIR BIN MOHD SORI
// IDs: 1201103668 | 1211101120 
// Emails: 1201103668@student.mmu.edu.my | 1211101120@student.mmu.edu.my  
// Phones: 0163256635 | 01158455813
// ********************************************************* 


#include "pf/helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Alien 
{
public:
    int health;
    int attack;

    Alien() : health(100), attack(10) {}
};

class Zombie 
{
public:
    int health;
    int attack;

    Zombie() : health(250), attack(5) {}
};


class Board
{
private:
    vector<vector<char>> map_;
    int dimX_, dimY_;
    int numZ;
    Alien alien_;
    Zombie zombie_;

public:
    Board(int dimX = 15, int dimY = 5, int numZ = 1);
    void init(int dimX, int dimY, int numZ);
    void display() const;
    void setDimX(int dimX);
    void setDimY(int dimY);

    int getDimX() { return dimX_; }
    int getDimY() { return dimY_; }
};

Board::Board(int dimX, int dimY, int numZ)
{
    init(dimX, dimY, numZ);
    dimX_ = dimX;
    dimY_ = dimY;
}

void Board::init(int dimX, int dimY, int numZ)
{
    char objects[] = {'^', '>', '<', 'v', 'h', 'p', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int noOfObjects = 15;

    dimX_ = dimX;
    dimY_ = dimY;

    map_.resize(dimY_);
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_);
    }

    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }

    srand(time(0));
    while (numZ > 0)
    {
        int x = rand() % dimX_;
        int y = rand() % dimY_;
        if (map_[y][x] == ' ')
        {
            map_[y][x] = 'Z';
            numZ--;
        }
    }
    int centerX = dimX_ / 2;
    int centerY = dimY_ / 2;
    map_[centerY][centerX] = 'A';
}
void Board::display() const
{
    cout << " --------------------------------" << endl;
    cout << " =       Alien VS Zombie        =" << endl;
    cout << " --------------------------------" << endl;

    for (int i = 0; i < dimY_; ++i)
    {
        for (int r = 0; r < 1; r++)
        {
            cout << " ";
        }
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << setw(2) << (dimY_ - i);
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    cout << " ";
    for (int r = 0; r < 1; r++)
    {
        cout << " ";
    }
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    for (int r = 0; r < 1; r++)
    {
        cout << " ";
    }
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int r = 0; r < 1; r++)
    {
        cout << " ";
    }
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << "                                         " << endl;
    cout << "                                         " << endl;
    cout << "Alien: Life " << alien_.health << ", Attack " << alien_.attack << endl;
    cout << "Zombie: Life " << zombie_.health << ", Attack " << zombie_.attack << endl;
    cout << endl
         << endl;
    
}

void Board::setDimX(int dimX)
{
    dimX_ = dimX;
}

void Board::setDimY(int dimY)
{
    dimY_ = dimY;
}
int main()
{
    int dimX, dimY, numZ;
    cout << "             Default Game Settings                " << endl;
    cout << "Board Rows      : 15                              " << endl;
    cout << "Board Columns   : 5                               " << endl;
    cout << "                                                  " << endl;
    cout << "Do you want to customise the game settings? (1=yes, 0=no)" << endl;
    cin >> dimX;
    if (dimX == 1)
    {
        cout << "             Board Settings   " << endl;
        cout << "Enter custom gameboard width: ";
        cin >> dimX;
        cout << "Enter custom gameboard height: ";
        cin >> dimY;
        cout << "Enter the number of zombies: ";
        cin >> numZ;

    }
    else
    {
        dimX = 15;
        dimY = 5;
        numZ = 1;
    }
    Board game(dimX, dimY);
    game.init(dimX, dimY, numZ);
    game.display();
    return 0;
}
