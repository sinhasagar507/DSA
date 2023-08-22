/* N Queen Problem */ 
#include <iostream>
#include <vector>
using namespace std;

bool isItSafeToPlace(vector<vector<int>> board, int row, int col)
{ 
    // Hmm haina sirf upr vaali queens hi check krenge. Baaki nai krenge... Cause niche toh hmne dala hi nai hai
    // vertically up 
    int r = row-1; 
    
    int c = col; 
    
    while(row>=0)
    {
        if(board[r][c])
            return false; 
    
        r--; 
    }
    
    // horizontally left 
    r = row; 
    c = col-1; 
    
    while(c>=0)
    {
        if(board[r][c])
            return false; 
            
        c--; 
    }
    
    // diagonally left
    r = row-1; 
    c = col-1; 
    
    while((r>=0) && (c>=0))
    {
        if(board[r][c])
            return false; 
            
        r--;
        c--; 
    }
    

    
    // diagonally right
    r = row-1; 
    c = col+1; 
    
    while(r>=0 and c<board[0].size())
    {
        if(board[r][c])
            return false;
            
        r--; 
        c++; 
    }
    
    return true;
}

void solveNQueen(vector<vector<int>> board, int row, int col, int tq, int qpsf, string ans) 
{
    // An expert coder's approach 
    if(qpsf==tq) // If queens placed so far is equal to the total no. of queens, then return true 
    { 
        cout<<ans<<endl; 
        return;
    } 
    
    if(col==board[0].size()) // If all current columns have been traversed, we move to the next row 
    { 
      row++; 
      col=0; 
    }
    
    if(row==board[0].size()) // All rows have been traversed. We can't place any more queens 
    {
        return; 
    }
    
    // Check if its safe to place other queens 
    if(isItSafeToPlace(board, row, col))
    {
    // do. First of all I have placed a queen at a particular row and column 
    board[row][col] = 1;  
    
    // Recur. Try placing other queens
    solveNQueen(board, row, col+1, tq, qpsf+1, ans+"["+to_string(row)+", "+to_string(col)+"]"); 
    
    // Undo 
    board[row][col] = 0;
    } 
    
    // If unable to place in a particular row or column 
    solveNQueen(board, row, col+1, tq, qpsf, ans); 
}

int main()
{
    int m, n; // for specifying the number of rows and columns 
    cin >> m >> n; 
    vector<vector<int>> board(m, vector<int>(n, 0));
    solveNQueen(board, 0, 0, 4, 0, "");
    return 0; 
}

