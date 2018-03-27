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
    int findTargetSumWays(vector<int>& nums, int S) {
      const int bound = 1000;
      const int ofs = bound*2;
      if(nums.size() == 0 || abs(S) > bound) return 0;
      vector<vector<int>> DP(nums.size(),vector<int>(ofs*2+1,0));
      DP[0][nums[0] + ofs]++;
      DP[0][-nums[0]+ ofs]++;
      for(size_t i=1;i<nums.size();++i){
        for(int j=-bound;j<bound+1;++j){
          DP[i][j+ofs] = DP[i-1][j+nums[i]+ofs] + DP[i-1][j-nums[i]+ofs];
        }
      }
      return DP[nums.size()-1][S+ofs];
    }
};

int main(){
  Solution sol;
  //vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
  vector<int> nums = {1,1,1,1,1};
  cout << sol.findTargetSumWays(nums,3) << endl;

}
