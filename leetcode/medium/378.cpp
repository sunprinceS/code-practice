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
      int m = matrix.size(), n = 0;
      if(m) n = matrix[0].size();
      if(!m || !n) return -1;

      if(k == 0) return matrix[0][0];
      if(k == m * n) return matrix[m-1][n-1];

      int lb = matrix[0][0], rb = matrix[m-1][n-1];      
      int mid;
      int num_smaller;
      while(lb < rb){
        num_smaller = 0;
        mid = (lb + rb) / 2;
        for(auto &row: matrix) num_smaller += (distance(row.begin(), upper_bound(row.begin(), row.end(), mid)));

        if(num_smaller < k) lb = mid + 1;
        else rb = mid;
      }
      // note that lb == rb
      return lb;
    }
};

int main(){
  Solution sol;
  vector<vector<int>> mat;
  mat = {{1,5,9},{10,11,13},{12,13,15}};
  cout << sol.kthSmallest(mat,8) << endl;

  mat = {{1,7,10},{2,8,11},{3,9,1000}};
  cout << sol.kthSmallest(mat, 4) << endl;

}
