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
    int numTrees(int n) {
        vector<int> DP(n+1);
        DP[0] = DP[1] = 1;
        for(size_t i=2;i<=n;++i){
          for(size_t j=0;j<=n-1;++j){
            DP[i] += DP[j] * DP[i-1-j];
          }
        }
        return DP[n];
    }
};

int main(){
  Solution sol;
  cout << sol.numTrees(3) << endl;
  cout << sol.numTrees(4) << endl;

}
