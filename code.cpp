#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
    public:
        bool canplace(vector<vector<char>>&board, int i, int j,int number){
            for (int x=0;x<9;x++){
                if(board[x][j] == number || board[i][x] == number){
                    return false;
                }
            }
            int rn = sqrt(9);
            int sx =(i/rn)*rn;
            int sy =(j/rn)*rn;
    
            for(int x = sx; x<sx+rn; x++){
                for (int y = sy; y<sy+rn; y++){
                    if (board[x][y]==number){
                        return false;
                    }
                }
            }
            return true;
    
        }
        bool solve(vector<vector<char>>& board, int i, int j) {
            if(i==9){
                for(int i=0; i<9; i++){
                    for (int j=0; j<9; j++){
                        cout<<board[i][j]<<",";
                    }
                    cout<<endl;
                }
                return true;
            }
            if (j==9){
                return solve(board,i+1,0);
            }
            if (board[i][j]!='.'){
                return solve(board,i,j+1);
            }
            for (char number = '1';number<='9';number++){
                if(canplace(board,i,j,number)){
                    board[i][j]=number;
                    bool couldsolve = solve(board,i,j+1);
                    if (couldsolve == true){
                        return true;
                    }
                }
            }
            board[i][j]='.';
            return false;
            
        }
    
        void solveSudoku(vector<vector<char>>& board){
            solve(board,0,0);
        }
};

/*struct grid
{
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cout<<"▢";
        }
        cout<<endl;
    }
};*/
 

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution s;
    s.solveSudoku(board);

}