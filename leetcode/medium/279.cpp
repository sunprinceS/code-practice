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
    int numSquares(int n) {
      if(DP.empty()){
        DP.resize(n+1,0);
      }
      if(n == 0){
        return 0;
      }
      else if(is_sq(n)){
        return 1;
      }
      else{
        if(DP[n]){
          return DP[n];
        }
        else{
          int N = sqrt(n);
          int ret = INT_MAX;
          int num_sq;
          for(int i=1;i<=N;++i){
            num_sq = n/(i*i);
            ret = min(ret,num_sq + numSquares(n-num_sq * (i*i)));
          }
          DP[n] = ret;
          return ret;
        }
      }       
    }
    bool is_sq(int n){
      int sq_root = sqrt(n);
      return (sq_root * sq_root) == n;
    }
    vector<int> DP;
};

int main(){
  Solution sol;
  cout << sol.numSquares(6) << endl;
}
