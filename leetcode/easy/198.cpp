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
    int rob(vector<int>& nums) {
      if(!nums.empty()) return 0;
      vector<int> ret(robSub(nums,0));
      return max(ret[0],ret[1]);
    }
    vector<int> robSub(vector<int>& nums,int idx){
      vector<int> ret(2);
      if(idx == nums.size()-1){
        ret[1] = nums[idx];
      }
      else{
        vector<int> subRet(robSub(nums,idx+1));
        ret[1] = subRet[0] + nums[idx];
        ret[0] = max(subRet[0],subRet[1]);
      }
      return ret;
    }
};

int main(){
  Solution sol;
}
