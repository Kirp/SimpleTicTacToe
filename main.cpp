#include <iostream>

using namespace std;

//global variables here
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{'  ',' ',' '}};
char onePiece = '0';
char twoPiece = 'X';

//functions declarations here
void displayBoard();
void displayCoords();
void player1();
void player2();
bool pieceMover(int mov, char piece);
bool setChecker();
void AIsays();

int main()
{
    bool breakTheLoop = false;
    int mov;


    cout<<"tic tac toe thing"<<endl<<endl;
    displayBoard();

    while (!breakTheLoop)
    {
        player1();
        breakTheLoop = setChecker();
        if(breakTheLoop == true)
        {
            break;
        }
        player2();
        displayBoard();

        breakTheLoop = setChecker();

    }

    cout<<"Final Board status: "<<endl;
    displayBoard();



    return 0;
}

void player1()
{
    char playerId = '0';
    int move;
    bool loopBreak = false;
    while(!loopBreak)
    {

    cout<<"current board status is: "<<endl;
    displayBoard();
    displayCoords();
    cout<<"Your pieces are "<<playerId<<", state your move: ";
    cin>>move;
    cout<<endl;
    loopBreak = pieceMover(move, playerId);

    }

}

void player2()
{
    char playerId = 'X';
    int move;
    bool loopBreak = false;
    while(!loopBreak)
    {

    cout<<"current board status is: "<<endl;
    displayBoard();
    displayCoords();
    cout<<"Your pieces are "<<playerId<<", state your move: ";
    cin>>move;
    cout<<endl;
    loopBreak = pieceMover(move, playerId);

    }

}

bool pieceMover(int mov, char pid)
{
    char piece = pid;
    bool validMove = NULL;
    switch(mov)
    {
        case 1:
            if(board[0][0] != onePiece && board[0][0] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[0][0] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 2:
             if(board[0][1] != onePiece && board[0][1] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[0][1] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 3:
             if(board[0][2] != onePiece && board[0][2] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[0][2] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 4:
             if(board[1][0] != onePiece && board[1][0] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[1][0] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 5:
             if(board[1][1] != onePiece && board[1][1] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[1][1] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 6:
             if(board[1][2] != onePiece && board[1][2] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[1][2] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 7:
             if(board[2][0] != onePiece && board[2][0] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[2][0] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 8:
             if(board[2][1] != onePiece && board[2][1] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[2][1] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        case 9:
             if(board[2][2] != onePiece && board[2][2] != twoPiece)
            {
                cout<<"Valid move, Accepted and noted"<<endl;
                board[2][2] = piece;
                validMove = true;
            } else {cout<<"Invalid move"<<endl; validMove = false;}
            break;
        default:
            cout<<"Invalid selection "<<endl;
            validMove = false;
            break;
    }

    return validMove;
}

void displayBoard()
{
    for(int i = 0; i<= 2; i++)
    {
        cout<<board[i][0]<<"|"<<board[i][1]<<"|"<<board[i][2]<<endl;
    }

}

void displayCoords()
{
    cout<<"commands are as follows: "<<endl;
    cout<<"1 | 2 | 3"<<endl;
    cout<<"4 | 5 | 6"<<endl;
    cout<<"7 | 8 | 9"<<endl;
    cout<<endl;
}

bool setChecker()
{
    bool declarer = false;

    for(int i = 0; i<=2; i++)
    {
        if(board[i][0] == onePiece && board[i][1] == onePiece && board[i][2] == onePiece && declarer == false)
            {
              cout<<"Player 1 wins!"<<endl;
              declarer = true;
              break;
            }
    }

    for(int i = 0; i<=2; i++)
    {
        if(declarer == true)
        {
            break;
        }
        if(board[i][0] == twoPiece && board[i][1] == twoPiece && board[i][2] == twoPiece && declarer == false)
            {
              cout<<"Player 2 wins!"<<endl;
              declarer = true;
              break;
            }
    }

    for(int i = 0; i<=2; i++)
    {
        if(declarer == true)
        {
            break;
        }
        if(board[0][i] == onePiece && board[1][i] == onePiece && board[2][i] == onePiece && declarer == false)
            {
              cout<<"Player 1 wins!"<<endl;
              declarer = true;
              break;
            }
    }

    for(int i = 0; i<=2; i++)
    {
        if(declarer == true)
        {
            break;
        }
        if(board[0][i] == twoPiece && board[1][i] == twoPiece && board[2][i] == twoPiece && declarer == false)
            {
              cout<<"Player 2 wins!"<<endl;
              declarer = true;
              break;
            }
    }

    if(board[0][0] == twoPiece && board[1][1] == twoPiece && board[2][2] == twoPiece && declarer == false)
            {
              cout<<"Player 2 wins!"<<endl;
              declarer = true;

            }

    if(board[0][2] == twoPiece && board[1][1] == twoPiece && board[2][0] == twoPiece && declarer == false)
            {
              cout<<"Player 2 wins!"<<endl;
              declarer = true;

            }

    if(board[0][0] == onePiece && board[1][1] == onePiece && board[2][2] == onePiece && declarer == false)
            {
              cout<<"Player 1 wins!"<<endl;
              declarer = true;

            }

    if(board[0][2] == onePiece && board[1][1] == onePiece && board[2][0] == onePiece && declarer == false)
            {
              cout<<"Player 1 wins!"<<endl;
              declarer = true;

            }

    return declarer;
}
