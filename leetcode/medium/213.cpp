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
    int rob(vector<int>& nums) {
      if(nums.empty()) return 0;
      if(nums.size()==1) return nums[0];
      else{
        vector<int> r1 = subRob(nums,0,nums.size()-2);//steal 1
        vector<int> r2 = subRob(nums,1,nums.size()-1); //not steal 1
        return max((r1[0],r1[1]),max(r2[0],r2[1]));
      }
    }
  private:
    // the first is not stolen
    vector<int> subRob(vector<int>&nums,int idx,int end){
      vector<int> ret(2);
      if(idx == end){
        ret[1] = nums[idx];
      }
      else{
        vector<int> subRet(subRob(nums,idx+1,end));
        ret[1] = subRet[0] + nums[idx];
        ret[0] = max(subRet[0],subRet[1]);
      }
      return ret;
    }
};
int main(){
  Solution sol;
  vector<int> nums = {1,1};
  cout << sol.rob(nums) << endl;
}
