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
    int uniquePaths(int m, int n) {
      vector<vector<int> > DP(m,vector<int>(n,1));
      for(size_t i=1;i<m;++i){
        for(size_t j=1;j<n;++j){
          DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
      }
      return DP[m-1][n-1];
    }
};

int main(){
  Solution sol;
}
