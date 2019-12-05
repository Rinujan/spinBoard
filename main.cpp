
#include <iostream>
#include "spinBoard.h"
using namespace std;
int main()

{
    spinBoard spinBoardobj(30,6);
    
    int positions,ans,ans2,times;
    
    cout<< "Please initialize the board. Enter the number of positions you want to shift left."<<endl;
    cin>>positions;
    for(int i=0;i<positions;i++){
        spinBoardobj.shiftLeft();
    }
cout<< "Spinning...";
    spinBoardobj.spin();
    cout<<"You board looks like"<<endl;
    cout<< spinBoardobj;
    while(ans!=3){
    cout<< "Choose from the following menu: 1. Shift 2.Spin 3. Quit"<<endl;
    cin>> ans;
    
    switch(ans){
        case 1:{
            cout<< "How many times would you like to shift your position"<<endl;
            cin>>times;
            cout<< "Would you like to shift 1.left 2.right"<<endl;
            cin>>ans2;
            if( ans2==1){
                for(int i=0;i<times;i++)
                {
                spinBoardobj.shiftLeft();
                }
                cout<<spinBoardobj<<endl;

            }
            else
            {
                for(int i=0;i<times;i++)
                {
                    spinBoardobj.shiftRight();
                }
                cout<<spinBoardobj<<endl;

            }
            break;
        }
            
        case 2:{
            spinBoardobj.spin();
            cout<<spinBoardobj<<endl;
            break;

        }
        case 3:{
            break;
        }
    }
    }
    spinBoardobj.isSolved();
    if(spinBoardobj.isSolved()==true){
        cout<<"Congratuations you have solved the spinBoard game"<<endl;
    }
    if(spinBoardobj.isSolved()==false){
        cout<<"Sorry, you did not solve the game"<<endl;
    }

    return 0;
    
    }

