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
    int totalNQueens(int n) {
      vector<bool> col_check(n);
      vector<bool> sum_check(2 * n - 1);
      vector<bool> diff_check(2 * n - 1);

      int ans = 0;
      dfs(ans, 0, n, col_check, sum_check, diff_check);

      return ans;
    }

    void dfs(int& ans, int i, int n, 
             vector<bool>& col_check, vector<bool>& sum_check, vector<bool>& diff_check){

      if (i == n) {++ans; return;}

      for(int j=0; j<n ;++j){
        if(!col_check[j] && !sum_check[i + j] && !diff_check[(n-1) + i - j]){
          col_check[j] = true;
          sum_check[i + j] = true;
          diff_check[(n-1) + i - j] = true;
          dfs(ans, i+1, n, col_check, sum_check, diff_check);
          col_check[j] = false;
          sum_check[i + j] = false;
          diff_check[(n-1) + i - j ] = false;
        }
      }
    }
};

int main(){
  Solution sol;

  //cout << sol.solveNQueens(1) << endl;
  //cout << sol.solveNQueens(2) << endl;
  //cout << sol.solveNQueens(3) << endl;
  //cout << sol.solveNQueens(4) << endl;
  cout << sol.totalNQueens(4) << endl;
  //cout << sol.solveNQueens(6) << endl;
  //cout << sol.solveNQueens(7) << endl;
  //cout << sol.solveNQueens(8) << endl;
}
