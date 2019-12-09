#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
return s<<"("<<p.first<<","<<p.second<<")";
}

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
s<<"[ ";
for (auto it : c) s << it << " ";
s<<"]";
return s;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      vector<vector<bool>> col_check(9);
      for(auto& v: col_check) v = vector<bool>(9);
      vector<vector<bool>> row_check(9);
      for(auto &v: row_check) v = vector<bool>(9);
      vector<vector<bool>> block_check(9);
      for(auto &v: block_check) v = vector<bool>(9);

      for(int i=0; i<9;++i){
        for(int j=0; j<9; ++j){
          if(board[i][j] != '.'){
            int b = 3 * (i/3) + (j/3);
            row_check[i][board[i][j]-'1'] = true;
            col_check[j][board[i][j]-'1'] = true;
            block_check[b][board[i][j]-'1'] = true;
          }
        }
      }
      dfs(board, 0 ,0, col_check, row_check, block_check);
    }

    bool dfs(vector<vector<char>>& board, int i, int j, 
             vector<vector<bool>>& col_check, vector<vector<bool>>& row_check, vector<vector<bool>>& block_check){
      if (j == 9){ ++i; j=0;}
      if (i == 9) return true;

      int b = 3 * (i/3) + (j/3);

      if(board[i][j] == '.'){
        for(int ci = 0; ci<9; ++ci){

          if (!row_check[i][ci] && !col_check[j][ci] && !block_check[b][ci]){
            board[i][j] = ci + '1';
            row_check[i][ci] = true;
            col_check[j][ci] = true;
            block_check[b][ci] = true;

            if(dfs(board, i, j+1, col_check, row_check, block_check)){
              return true;
            }
            else{
              board[i][j] = '.';
              row_check[i][ci] = false;
              col_check[j][ci] = false;
              block_check[b][ci] = false;
            }
          }
        }
        return false;
      }
      else return dfs(board, i, j+1, col_check, row_check, block_check);
    }

    //bool is_valid(vector<vector<char>>& board, int i, int j, char c){
      //for(int ii = 0; ii <9; ++ii){
        //if(i != ii && board[ii][j] == c) return false;
      //}
      //for(int jj=0;jj<9;++jj){
        //if(j != jj && board[i][jj] == c) return false;
      //}

      //int row = i/3;
      //int col = j/3;
      //for(int ii = 0; ii <3; ++ii){
        //for(int jj = 0; jj < 3; ++jj){
          //if(board[ 3* row+ii][3 * col+jj] == c && (( 3* row + ii != i) || (3 * col + jj != j))) return false;
        //}
      //}
      //return true;
    //}
};

int main(){
  Solution sol;
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
  sol.solveSudoku(board);
  cout << board << endl;
}
