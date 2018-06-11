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

//看一下 https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66207/My-C++-soluation-using-Binary-search-Tree-model-beats-100~~~~
class Solution{
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=0;
        if(m) n = matrix[0].size();
        if(!m || !n) return false;

        int l = 0,r = m;
        int mid;
        //find middle row
        while(l!=r){
          mid = (l+r) / 2;
          if(matrix[mid][0] < target)
            l = mid + 1;
          else
            r = mid;
        }
        int row_mid = r;
        if (!row_mid){
          if(binary_search(matrix[0].begin(),matrix[0].end(),target)) return true;
          else return false;
        }

        //find middle column
        l = 0,r = n;
        while(l!=r){
          mid = (l+r) / 2;
          if(matrix[0][mid] < target)
            l = mid + 1;
          else
            r = mid;
        }
        int col_mid = r;
        if (!col_mid) return false;

        for(size_t i=0;i<m;++i){
          if(binary_search(matrix[i].begin(),matrix[i].end(),target)) return true;
        }
        return false;
    }
};

int main(){
  //vector<vector<int>> matrix({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}});
  vector<vector<int>> matrix({{5}});
  Solution sol;
  cout << sol.searchMatrix(matrix,5) << endl;
}
