#include "spinBoard.h"
#include "circulardoublylinkedlist.h"
spinBoard::spinBoard(int sizeofboard,int sizeofspinner){
    for (int i =1;i<=sizeofboard;i++){
        board.addTail(i);
    }
    spinnersize=sizeofspinner;
    boardsize=sizeofboard;
    //initializing the left end of spinner and right end of spinner
    board.left=board.exhptr;
    board.right=board.exhptr;
    for (unsigned int k = 0; k < spinnersize - 1; k++){
        board.right = board.right->next;
    }

    }
spinBoard::~spinBoard(){
    // no memory allocated
}
void spinBoard::shiftLeft()
{
    //this method is declared and defined in cdll.h and it shifts the position left once
    board.shiftrights();
   
}
void spinBoard::shiftRight()
{
    //this method is declared and defined in cdll.h and it shifts the position right once
    board.shiftlefts();


}
void spinBoard::spin()
{
    //leftmode pointing to leftmost of spiner,right node pointing to end of spinner. This helps me stay within the indices of the spinner to initiate the spin. x=left, y=right
    circulardoublylinkedlist<int>::Node *x = board.left;
    circulardoublylinkedlist<int>::Node *y = board.right;
    //swapping is taken place inside loop
    for (int c = 0; c < spinnersize / 2; ++c)
    {
        
        int temp = x->value;
        x->value = y->value;
        y->value = temp;
        
        x = x->next;
        y = y->prev;
    }
}
   bool spinBoard::isSolved()
    {
        circulardoublylinkedlist<int>::Node *tem = board.exhptr;
        while (tem->value != 1)//traverse to the position where 1 is being held
            tem = tem->next;
        for (int i = 1; i < boardsize; ++i){
            if (tem->value >tem->next->value)//check if next value bigger if not return false
                return false;
            tem=tem->next;//move to the next node to check if puzzle is solved
        }
        return true;
}


