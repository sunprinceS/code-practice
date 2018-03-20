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
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid.front().size();
      vector<vector<int>> DP(m,vector<int>(n,0));
      
      DP[0][0] = 0;
      for(size_t j=1;j<n;++j){
        DP[0][j] = DP[0][j-1] + grid[0][j-1];
      }
      for(size_t i=1;i<m;++i){
        DP[i][0] = DP[i-1][0] + grid[i-1][0];
      }
      for(size_t i=1;i<m;++i){
        for(size_t j=1;j<n;++j){
          DP[i][j] = min(DP[i-1][j] + grid[i-1][j],DP[i][j-1] + grid[i][j-1]);
        }
      }
      return DP[m-1][n-1] + grid[m-1][n-1];
    }
};

int main(){
  Solution sol;
  vector<vector<int>> ret = {{1,2,3},{4,5,6}};
  cout << sol.minPathSum(ret) << endl;
}
