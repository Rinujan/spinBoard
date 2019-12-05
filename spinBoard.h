#pragma once
#include "circulardoublylinkedlist.h"
#include <iostream>
using namespace std;
class spinBoardADT {
public:
    virtual void shiftLeft() = 0;
    virtual void shiftRight() = 0;
    virtual void spin() = 0;
    virtual bool isSolved() = 0;
};
class spinBoard :public spinBoardADT{
    int boardsize;
    int spinnersize;
    
public:
    circulardoublylinkedlist<int> board;
    spinBoard(int sizeofboard ,int sizeofspinner);
    ~spinBoard();
    //abstract functions were redefined to use in spinBoard.cpp
    virtual void shiftLeft();
    virtual void shiftRight();
    virtual void spin();
    virtual bool isSolved();
   friend std::ostream& operator << (std::ostream &os,const spinBoard &ts);
};
//print board
inline ostream& operator << (ostream& os, const spinBoard& ts)
{

    //initialize iterator for the game
     circulardoublylinkedlist<int>::Iterator game = ts.board.begin();
    //printing --- on top of spinner
    for (int i = 0; i < ts.spinnersize; i++)
        cout << "---";
    cout << endl;
    
    for (int i = 0; i < ts.boardsize;i++,++game)//++ iterator
    {
        //separating spinner from rest of the board
        if (i == 0 || i == ts.spinnersize)
            cout << "|| ";
        os <<game.getValue()<<" ";//get values of pointer nodes using iterator getter
        
    }
    cout <<endl;
//printing ----- under the spinner
    for (int i = 0; i < ts.spinnersize; i++)
        cout << "---";
    cout << endl;
    return os;
}





