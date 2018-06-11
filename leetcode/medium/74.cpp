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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=0;
        if(m) n = matrix[0].size();
        if(!m || !n) return 0;
        int l = 0, r = m*n-1;
        int mid;
        while(l!=r){
          mid = (l+r)/2;
          if(matrix[mid/n][mid%n] < target)
            l = mid+1;
          else
            r = mid;
        }
        return matrix[r/n][r%n] == target;
    }
};

int main(){
  //vector<vector<int>> matrix({{1,3,5,7},{10,11,16,20},{23,30,34,50}});
  vector<vector<int>> matrix({{}});
  Solution sol;
  cout << sol.searchMatrix(matrix,3) << endl;
}
