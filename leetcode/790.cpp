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
    int numTilings(int N) {
      vector<unsigned int> dp(4);
      dp[0] = 1;
      dp[1] = 1;
      dp[2] = 2;
      if (N<3) return dp[N];

      for(int i=3;i<=N;++i){
        dp[i%4] = 2 * dp[(i-1)%4] + dp[(i-3)%4];
        dp[i%4] = dp[i%4] % 1000000007;
      }
      return dp[N%4];
    }
};


int main(){
  Solution sol;
  cout << sol.numTilings(1) << endl;
  cout << sol.numTilings(2) << endl;
  cout << sol.numTilings(3) << endl;
  cout << sol.numTilings(4) << endl;
  cout << sol.numTilings(30) << endl;
}
