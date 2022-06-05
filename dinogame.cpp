//this code is written by muhib Arshad

//Libararies
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
using namespace std;

//Global Variables
const int row = 5;
const int col = 70;

//Prototypes Functions
bool right_infinitemove(char borad[][col], int row, int &pos);
void jump(char board[][col], int row,int x) ;
int  back(char board[][col], int row,int &score) ;

//Main
int main()
{
    //local variables
    int pos = col - 1;
    char ch;
    char board[row][col];
    int score=0;
    int x;

    //Initializing the grid
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = '_';
        }
    }
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }

    //setting position of emoji (dino) and cactus ($)
    board[row - 1][col - 1] = '$';
    board[row - 1][15] = 1;
    for (int i = 0; i < 10; i++)
    {
        cout << "\n";
    }

    //Displaying the grid
    for (int i = 0; i < row; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < col; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    bool flag = false;
    do
    {

    //   getch();

       //Infinite move of the cactus from right to left
        flag = right_infinitemove(board, row, pos);
        system("cls");
       
        for (int i = 0; i < 10; i++)
        {
            cout << "\n";
        }
        for (int i = 0; i < row; i++)
        {
            cout << "\t\t";
            for (int j = 0; j < col; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }
        
        //On kibhit
        x=kbhit(); 
        if(x==1)
        {
            //Jump the dino
            jump(board, row,x);

            //back jump dino
            back(board, row, score);
            x=0;
        }
       
    } while (flag == false);
    //If both cactus and dino hits game over
    if (flag == true)
    {
        cout << "You lose!" << endl;
    }
}

//Infinte move of the cactus 
bool right_infinitemove(char board[][col], int row, int &pos)
{
    if (board[row - 1][pos - 1] == 1)
    {
        return true;
    }
    if (pos != 0)
    {
        int temp;
        temp = board[row - 1][pos - 1];
        board[row - 1][pos - 1] = board[row - 1][pos];
        board[row - 1][pos] = temp;
        pos--;
        return false;
    }
    if (pos == 0)
    {
        int temp;
        temp = board[row - 1][pos];
        board[row - 1][pos] = board[row - 1][col - 1];
        board[row - 1][col - 1] = temp;
        pos = col - 1;
        return false;
    }
}

//Jump of te dino
void jump(char board[][col], int row,int x)
{
        if (board[row - 1][17] == '$')
        {
            int temp;
            temp = board[row - 1][15];
            board[row - 1][15] = '_';
            board[row - 2][15] = temp;
        }
        
    
}

//Back jump of the dino when cactus pass out
int back(char board[][col], int row,int &score)
{
    if (board[row - 1][12] == '$')
    {
        int temp;
        temp = board[row - 2][15];
        board[row - 2][15] = ' ';
        board[row - 1][15] = temp;
        // score+;
        return score;
    }

}