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
    vector<int> sortedSquares(vector<int>& A) {
      if (A.empty()) return {};
      vector<int> ret;
      ret.reserve(A.size());
      if(A.back() <= 0){
        for(int i=A.size()-1;i>=0;--i) ret.push_back(A[i] * A[i]);
      }
      else if(A[0] >= 0) {
        for(int i=0;i<A.size();++i) ret.push_back(A[i] * A[i]);
      }
      else{
        int pos_i, neg_i, num_zeros;
        auto p = equal_range(A.begin(), A.end(), 0);
        pos_i = p.second - A.begin();
        neg_i = p.first - A.begin();
        num_zeros = pos_i - neg_i;
        for(int i=0; i< num_zeros; ++i) ret.push_back(0);
        --neg_i;

        while(neg_i !=-1 || pos_i != A.size()){
          if(neg_i >= 0 && pos_i <= A.size()-1){
            if(-1 * A[neg_i] < A[pos_i]){
              ret.push_back(A[neg_i] * A[neg_i]);
              --neg_i;
            }
            else{
              ret.push_back(A[pos_i] * A[pos_i]);
              ++pos_i;
            }
          }
          else if(neg_i == -1){
            ret.push_back(A[pos_i] * A[pos_i]);
            ++pos_i;
          }
          else{
            ret.push_back(A[neg_i] * A[neg_i]);
            --neg_i;
          }
        }
      }
      return ret;
    }
};


int main(){
  Solution sol;
  vector<int> nums;
  nums = {-4,-1,0,3,10};
  cout << sol.sortedSquares(nums) << endl;
  nums = {-7,-3,2,3,11};
  cout << sol.sortedSquares(nums) << endl;
}
