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

/* Key Idea:
 * first  reverse up and down, then swap the symmetry
 * 如果想逆時鐘，則是reverse right and left, then swap the symmetry
 * */
class Solution{
  public:
    void rotate(vector<vector<int>>& matrix) {
      reverse(matrix.begin(),matrix.end());
      for(size_t i=0;i<matrix.size();++i){
        for(size_t j=i+1;j<matrix.size();++j){
          swap(matrix[i][j],matrix[j][i]);
        }
      }
    }
};

int main(){
  Solution sol;
}
