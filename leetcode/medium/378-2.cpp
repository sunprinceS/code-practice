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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      int lb = matrix[0][0];
      int rb = matrix[n-1][n-1];

      if(k == 1) return lb;
      else if(k == n * n) return rb;
      else{
        int mid;
        int n_smaller;
        int n_add;
        while(lb < rb){
          n_smaller = 0;
          mid = (lb + rb) / 2;
          for(auto &row: matrix){
            n_add = distance(row.begin(), upper_bound(row.begin(), row.end(), mid));
            n_smaller += n_add;
            if(n_add == 0) break;
          }

          if(n_smaller < k) lb = mid + 1;
          else rb = mid;// cannot directly return!
        }
        return lb;
      }

        
    }
};

int main(){
  Solution sol;
  vector<vector<int>> matrix;
  int k;

  matrix = {{1,5,9},{10,11,13},{12,13,15}};
  cout << sol.kthSmallest(matrix, 8) << endl;

  matrix = {{20000000}};
  cout << sol.kthSmallest(matrix, 1) << endl;
}
