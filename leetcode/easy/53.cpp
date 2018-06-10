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
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> DP(nums.size());
        int mmax = nums[0];
        DP[0] = nums[0];
        for(size_t i=1;i<nums.size();++i){
          DP[i] = max(DP[i-1] + nums[i],nums[i]);
          if(mmax < DP[i])
            mmax = DP[i];
        }
        return mmax;
    }
};

int main(){
  Solution sol;
  vector<int> vec({2});
  cout << sol.maxSubArray(vec) << endl;
}
