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

class Solution{
  public:
    bool exist(vector<vector<char>>& board, string word) {
      for(int y=0; y< board.size(); ++y){
        for(int x=0; x < board[y].size(); ++x){
          char c = board[y][x];
          if(dfs(board, word, 0, x, y)) return true;
          board[y][x] = c;
        }
      }
      return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int pos, int x, int y){
      if(board[y][x] == word[pos]){
        board[y][x] = '*';
        if(pos == word.size() - 1) return true;
        else{
          if(x-1 >=0){
            char c = board[y][x-1];
            if(dfs(board, word, pos+1, x-1, y)) return true;
            board[y][x-1] = c;
          }
          if(x+1 < board[y].size()){
            char c = board[y][x+1];
            if(dfs(board, word, pos+1, x+1, y)) return true;
            board[y][x+1] = c;
          }

          if(y-1 >=0){
            char c = board[y-1][x];
            if(dfs(board, word, pos+1, x, y-1)) return true;
            board[y-1][x] = c;
          }

          if(y+1 < board.size()){
            char c = board[y+1][x];
            if(dfs(board, word, pos+1, x, y+1)) return true;
            board[y+1][x] = c;
          }
          return false;
        }
      }
      else{
        return false;
      }
    }
};

int main(){
  Solution sol;
  vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  string word("ABCB");
  cout << sol.exist(board, word) << endl;
}
