/******************************************************************************
=========
N Queen
=========
The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. 
which will be acheived by
1) Only one Queen in a row
2) Only one Queen in a column
3) Only one Queen Diagonaly

Complexity
===========
Space Complexity : O(n) -Single diamentional array
Time Complexity : Dynamic backtracking program - Hard

Solution:
=========
As there is only one Queen per row. Representing the chessboard grid as a single diamentional array, 
  => index Representing the row, value in that index will rpresent the column in which th queen is placed
  => finding which position to place the queen. pick [row,col] and check whether it is safe to place the queen there 
  => place the queen in the column when all there above conditions are satisied
Logic: placeQueen
======  1) iterate through the grid. where row is represented as index of the board and column is represented as values
        2) in a 2-diamentional array every row and col is checked[is it safe to place Queen there]
        3) if non of the column satisfies, program goes back a row and try placing in the next column in row-1
        4) step 3 is put in a backward loop till a Queen can be placed in a non conflict position in the above rows then program proceeds with step 2
        5) process is continued till the full grid is populated            

Logic: isSafe
======
    1.In same row (Single diamentional array will satisfy this condition
    2.In same column (traversel throu the array O(n) to find whether the particulatar column is occupied by another queen)
    3.Diagonal - within the board limit, 
                 a) all diagonal upper left side of [row,col] (eg: row-1 and column-1)
                 b) all diagonal upper right side of [row,col] (eg:row-1 and column+1) 
*******************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;


class grid
{
   
   public:
    int boardSize=10;
    int board[10];
    
   public:
    grid();
    void placeQueen();
    bool isSafe(int row, int position);
    void printBoard();
};

/*Method        : printBoard
  Functionality : prints the Board structure with values where queen 'Q' is placed and empty is represented by '*'
*/

void grid::printBoard()
{
    cout<<"\t NQueen Board of size : "<<boardSize<<"\n\n\n";
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<boardSize;j++)
        {
            if(board[i]==j) 
               cout<<"  Q  ";
            else
               cout<<"  *  ";
        }
        cout<<"\n";
    }
}
/*Method : grid
  Type   : class constructor
  Functionality : initialize all the grid values to -1
*/
grid::grid()
{
    for(int i=0;i<boardSize;i++) 
       board[i]=-1;
}

/*Method    : placeQueen
  Arguments : Nill
  Return    : Nill
  Functionality : populate the N*N chessboard
  Logic     : 1) iterate through the grid. where row is represented as index of the board and column is represented as values
              2) in a 2-diamentional array every row and col is checked[is it safe to place Queen there]
              3) if non of the column satisfies, program goes back a row and try placing in the next column in row-1
              4) step 3 is put in a backward loop till a Queen can be placed in a non conflict position in the above rows then program proceeds with step 2
              5) process is continued till the full grid is populated            
*/

void grid::placeQueen()
{
 
    bool placed=0;
    int row=0,col=0;
    
    while(row<boardSize)
    { 
        if(board[row]==boardSize-1) 
        { 
            board[row]=-1; 
            row--;
        }
        for(col=board[row]+1;col<boardSize;col++)
        {
            if(isSafe(row,col))
            {
                board[row]=col;
                placed=1;
                break;
            }
        }
        if(placed)
        {
            row++;
        }
        else
        {
            row--;    
        }
        placed=0;
    }
}

/*Method    : isSafe
  Arguments : int row, int position(col) of a chessBoard
  Return    : bool - is the possition safe to place the Queen
  Logic     :  Queen cannot be placed 
          1.In same row (Single diamentional array will satisfy this condition
          2.In same column (traversel throu the array O(n) to find whether the particulatar column is occupied by another queen)
          3.Diagonal - within the board limit, 
                 a) all diagonal upper left side of [row,col] (eg: row-1 and column-1)
                 b) all diagonal upper right side of [row,col] (eg:row-1 and column+1) 
*/
bool grid::isSafe(int row, int position)
{
  
    
    
    for(int i=0;i<row;i++)
    {
       if(board[i]==position) // Same column check
           return 0;
    }
 
    int i=row;
    for(int k=1;i-k>-1&&k<boardSize;k++) // Diagonal top both sides needs to be considered
        {
//       cout<<"\nChecking for row : "<<i-k<<"  k : "<<k<<"  board[i-k] :: "<<board[i-k]<<"  For Diag position : "<<position-k<<" and "<<position+k;
         if((board[i-k]==position-k && position-k!=-1) || (board[i-k]==position+k && position+k<boardSize)) 
              {
//             cout<<"\nReturning FALSE\n";
                   return 0;
              }
//          cout<<"\ncontinue check\n";
            }
 // cout<<"\nReturning TRUE\n";

  return 1;
}


int main()
{
   grid chessBoard;
   chessBoard.placeQueen();  
   chessBoard.printBoard();
}
