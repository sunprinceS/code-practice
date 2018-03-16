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
    void DFS(vector<vector<char>>&grid,int i,int j){
      grid[i][j] = '0';
      if(i+1 < grid.size() && grid[i+1][j] == '1'){
        DFS(grid,i+1,j);
      }
      if(i-1 >= 0 && grid[i-1][j] == '1'){
        DFS(grid,i-1,j);
      }
      if(j+1 < grid[0].size() && grid[i][j+1] == '1'){
        DFS(grid,i,j+1);
      }
      if(j-1 >= 0 && grid[i][j-1] == '1'){
        DFS(grid,i,j-1);
      }
    }
    int numIslands(vector<vector<char>>& grid) {
      int cnt = 0;
      for(size_t i=0;i<grid.size();++i){
        for(size_t j=0;j<grid[0].size();++j){
          if(grid[i][j] == '1'){
            ++cnt;
            DFS(grid,i,j);
          }
        }
      }
      return cnt;
    }
};

int main(){
  Solution sol;
  //vector<vector<char> > grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
  //vector<vector<char> > grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
  //vector<vector<char> > grid = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
  vector<vector<char> > grid = {{'1','0','1'},{'1','1','1'},{'1','0','1'}};
  cout << sol.numIslands(grid) << endl;
}
